/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:51:16 by piboidin          #+#    #+#             */
/*   Updated: 2022/02/04 11:51:20 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_get_height(char *file)
{
	write(1, "Ici\n", 4);
	char	*line;
	int		fd;
	int		height;

	write(1, "Je rentre dans height\n", 22);
	fd = open(file, O_RDONLY, 0);
	height = 0;
	while (ft_get_next_line(fd, &line))
	{
		write(1, "Je rentre dans while\n", 20);
		height++;
		free(line);
	}
	write(1, "Je sors du while\n", 16);
	close(fd);
	return (height);
}

int	ft_get_width(char *file)
{
	char	*line;
	int		fd;
	int		width;

	width = 0;
	fd = open(file, O_RDONLY, 0);
	write(1, "Je rentre dans GNL\n", 19);
	ft_get_next_line(fd, &line);
	write(1, "Je sors de GNL\n", 15);
	width = ft_count_word(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	ft_matrix(int *data, char *line)
{
	char	**str;
	int		i;

	str = ft_split(line, ' ');
	i = 0;
	while (str[i])
	{
		data[i] = ft_atoi(str[i]);
		free(str[i]);
		i++;
	}
}

void	ft_file_reader(char *file, s_fdf *data)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	data->width = ft_get_width(file);
	write(1, "Je passe width\n", 15);
	data->height = ft_get_height(file);
	write(1, "Je passe height\n", 16);
	data->width = ft_get_width(file);
	data->alt = (int **)malloc(sizeof(int *) * (data->height + 1));
	write(1, "Avant le while 1\n", 17);
	while (i <= data->height)
		data->alt[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	fd = open(file, O_RDONLY, 0);
	i = 0;
	write(1, "ICI 1\n", 6);
	while (ft_get_next_line(fd, &line))
	{
		ft_matrix(data->alt[i], line);
		free(line);
		i++;
	}
	close(fd);
	data->alt[i] = NULL;
}
