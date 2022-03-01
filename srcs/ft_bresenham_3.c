/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:37:05 by piboidin          #+#    #+#             */
/*   Updated: 2022/02/28 15:37:06 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

bool	ft_bounds_error(t_fdf *file, t_point curr)
{
	return (curr.y < 0 || curr.x < 0
		|| curr.y > file->win_hight - 1 || curr.x > file->win_width - 1);
}

void	ft_init_point(t_fdf *file, t_point *dest, t_point *src)
{
	dest->value = file->map[src->y][src->x].value;
	if (!file->map[src->y][src->x].color)
		dest->color = ft_get_color(file, dest->value);
	else
		dest->color = file->map[src->y][src->x].color;
	dest->value *= file->elevation_zoom;
	src->x *= file->grid_zoom;
	src->y *= file->grid_zoom;
	src->x -= ((file->abs_count - 1) * file->grid_zoom) / 2;
	src->y -= ((file->ord_count - 1) * file->grid_zoom) / 2;
	ft_x_rot(&src->y, &dest->value, file->x_rot);
	ft_y_rot(&src->x, &dest->value, file->y_rot);
	ft_z_rot(&src->x, &src->y, file->z_rot);
	if (file->projection == 'i')
		ft_iso_conv(&src->x, &src->y, dest->value);
	dest->x = src->x + (file->win_width / 2) + file->x_shift;
	dest->y = src->y + (file->win_hight / 2) + file->y_shift;
}

void	ft_init_line(t_fdf *file)
{
	file->line.delta.x = file->line.end.x - file->line.start.x;
	file->line.delta.y = file->line.end.y - file->line.start.y;
	file->line.curr = file->line.start;
	if (ft_is_grad(file->line.start, file->line.end))
	{
		file->line.diff = 2 * file->line.delta.y - file->line.delta.x;
		file->yi = 1;
		if (file->line.delta.y < 0)
		{
			file->yi = -1;
			file->line.delta.y = -file->line.delta.y;
		}
	}
	else
	{
		file->line.diff = 2 * file->line.delta.x - file->line.delta.y;
		file->xi = 1;
		if (file->line.delta.x < 0)
		{
			file->xi = -1;
			file->line.delta.x = -file->line.delta.x;
		}
	}
}

void	ft_iso_conv(int *x, int *y, int z)
{
	int	px;
	int	py;

	px = *x;
	py = *y;
	*x = (px - py) * cos(TAN_30_DEGREES);
	*y = (px + py + 1) * sin(TAN_30_DEGREES) - z;
}
