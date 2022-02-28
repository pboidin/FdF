/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:38:35 by piboidin          #+#    #+#             */
/*   Updated: 2022/02/28 15:38:37 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mod_projection(int keycode, t_fdf *file)
{
	file->x_shift = 0;
	file->y_shift = 0;
	file->x_rot = 0;
	file->y_rot = 0;
	file->z_rot = 0;
	if (keycode == P)
		file->projection = 'p';
	else if (keycode == I)
		file->projection = 'i';
}

void	ft_mod_translation(int keycode, t_fdf *file)
{
	if (keycode == UP)
		file->y_shift -= 10;
	else if (keycode == DWN)
		file->y_shift += 10;
	else if (keycode == LFT)
		file->x_shift -= 10;
	else if (keycode == RT)
		file->x_shift += 10;
}

void	ft_mod_transformation(int keycode, t_fdf *file)
{
	if (keycode == A)
		file->z_rot -= .1;
	else if (keycode == COL)
		file->z_rot += .1;
	else if (keycode == S)
		file->x_rot += .1;
	else if (keycode == L)
		file->x_rot -= .1;
	else if (keycode == D)
		file->y_rot += .1;
	else if (keycode == K)
		file->y_rot -= .1;
}

void	ft_mod_zoom(int keycode, t_fdf *file)
{
	if (keycode == F)
	{
		file->grid_zoom++;
		file->elevation_zoom++;
	}
	else if (keycode == J)
	{
		file->grid_zoom--;
		file->elevation_zoom--;
	}
	else if (keycode == PLS)
		file->elevation_zoom++;
	else if (keycode == MNS)
		file->elevation_zoom--;
	if (file->grid_zoom > 100)
		file->grid_zoom = 100;
	if (file->elevation_zoom > 100)
		file->elevation_zoom = 100;
	if (file->grid_zoom < 1)
		file->grid_zoom = 1;
	if (file->elevation_zoom < 1)
		file->elevation_zoom = 1;
}
