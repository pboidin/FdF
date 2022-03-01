/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:37:43 by piboidin          #+#    #+#             */
/*   Updated: 2022/02/28 15:37:44 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_init_min_max(t_fdf *file)
{
	int	x;
	int	y;

	y = 0;
	file->min_elevation = file->map[0][0].value;
	file->max_elevation = file->map[0][0].value;
	while (y < file->ord_count)
	{
		x = 0;
		while (x < file->abs_count)
		{
			if (file->map[y][x].value < file->min_elevation)
				file->min_elevation = file->map[y][x].value;
			else if (file->map[y][x].value > file->max_elevation)
				file->max_elevation = file->map[y][x].value;
			x++;
		}
		y++;
	}
}

static int	ft_fdf_hex_len(char *hex)
{
	int	i;

	i = 0;
	while (ft_isalnum(hex[i]))
		i++;
	return (i);
}

static uint32_t	ft_tool(char *hex)
{
	long	hex_l;
	int		i;
	int		len;
	uint8_t	byte;

	if (ft_memcmp("0x", hex, 2) != 0)
		return ('\0');
	hex_l = 0;
	i = 0;
	len = ft_fdf_hex_len(hex);
	while (i < len)
	{
		if (ft_isdigit(hex[i]))
			byte = hex[i] - '0';
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			byte = hex[i] - 'a' + 10;
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			byte = hex[i] - 'A' + 10;
		hex_l = (hex_l << 4) | (byte & 0xF);
		i++;
	}
	return (hex_l);
}

static void	ft_init_map_row(t_fdf *file, int fd, char *line)
{
	int	i;

	i = 0;
	file->map[file->ord] = (t_elev *)malloc(sizeof(t_elev) * file->abs_count);
	if (!(file->map[file->ord]))
		ft_close(file, fd, line, "Memory allocation error");
	while (line[i] && file->abs != file->abs_count)
	{
		while (ft_isspace(line[i]))
			i++;
		file->map[file->ord][file->abs].value = ft_atoi(&line[i]);
		file->map[file->ord][file->abs].color = '\0';
		if (line[i] == '-')
			i++;
		while (ft_isdigit(line[i]))
			i++;
		if (line[i] == ',')
		{
			file->map[file->ord][file->abs].color = (int)ft_tool(&line[++i]);
			while (ft_isalnum(line[i]) && line[i])
				i++;
		}
		file->abs++;
	}
}

void	ft_init_map(t_fdf *file)
{
	t_gnl	gnl;

	gnl.line = NULL;
	gnl.fd = ft_open_file(file, file->filemap);
	gnl.ret = ft_gnl(gnl.fd, &gnl.line);
	if (gnl.ret == -1)
		ft_close(file, gnl.fd, gnl.line, "Memory allocation error");
	file->map = (t_elev **)malloc(sizeof(t_elev *) * file->ord_count);
	if (!(file->map))
		ft_close(file, gnl.fd, gnl.line, "Memory allocation error");
	while (gnl.ret == 1)
	{
		if (gnl.line[0] == 0)
			ft_close(file, gnl.fd, gnl.line, "Delete New Line");
		file->abs = 0;
		ft_init_map_row(file, gnl.fd, gnl.line);
		ft_free(gnl.line);
		gnl.ret = ft_gnl(gnl.fd, &gnl.line);
		if (gnl.ret == -1)
			ft_close(file, gnl.fd, gnl.line, "cannot read .fdf file");
		file->ord++;
	}
	ft_free(gnl.line);
	close(gnl.fd);
	ft_init_min_max(file);
}
