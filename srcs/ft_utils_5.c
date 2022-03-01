/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:38:26 by piboidin          #+#    #+#             */
/*   Updated: 2022/02/28 15:38:27 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_reset(t_fdf *file)
{
	mlx_destroy_image(file->mlx, file->img.img);
	file->img.img = mlx_new_image(file->mlx, file->win_width, file->win_hight);
	if (!(file->img.img))
		ft_exit_failed(file, "Could not create image");
	file->img.addr = mlx_get_data_addr(file->img.img,
			&file->img.bpp, &file->img.len, &file->img.end);
	ft_draw(file);
}

int	ft_key_press(int keycode, t_fdf *file)
{
	if (keycode == ESC)
		ft_exit_successful(file);
	else if (keycode == P || keycode == I)
		ft_mod_projection(keycode, file);
	else if (keycode == UP || keycode == DWN
		|| keycode == LFT || keycode == RT)
		ft_mod_translation(keycode, file);
	else if (keycode == A || keycode == COL || keycode == S
		|| keycode == L || keycode == D || keycode == K)
		ft_mod_transformation(keycode, file);
	else if (keycode == F || keycode == J
		|| keycode == PLS || keycode == MNS)
		ft_mod_zoom(keycode, file);
	ft_reset(file);
	return (0);
}

void	ft_failed_exit(char *message, char *memory)
{
	if (memory)
	{
		ft_free(memory);
		memory = NULL;
	}
	ft_putendl_fd(message, STDERR_FILENO);
	exit (EXIT_FAILURE);
}
