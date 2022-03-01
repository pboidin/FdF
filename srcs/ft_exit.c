/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:37:35 by piboidin          #+#    #+#             */
/*   Updated: 2022/02/28 15:37:37 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_free_mem(t_fdf *file)
{
	int	i;

	i = 0;
	if (file->map)
	{
		while (i < file->ord && file->map[i])
			ft_free(file->map[i++]);
		ft_free(file->map);
	}
	if (file->img.img)
		mlx_destroy_image(file->mlx, file->img.img);
	if (file->win)
		mlx_destroy_window(file->mlx, file->win);
	if (file->mlx)
		ft_free(file->mlx);
}

void	ft_exit_failed(t_fdf *file, char *error_message)
{
	ft_free_mem(file);
	ft_failed_exit(error_message, NULL);
}

int	ft_exit_successful(t_fdf *file)
{
	ft_free_mem(file);
	exit(EXIT_SUCCESS);
}

void	ft_close(t_fdf *file, int fd, char *line, char *err_msg)
{
	close(fd);
	ft_free_mem(file);
	ft_error_exit(line, err_msg);
}
