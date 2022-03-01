/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:37:28 by piboidin          #+#    #+#             */
/*   Updated: 2022/02/28 15:37:29 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_point	ft_right(t_point step)
{
	step.x++;
	return (step);
}

static t_point	ft_down(t_point step)
{
	step.y++;
	return (step);
}

void	ft_draw(t_fdf *file)
{
	t_point	step;

	step.y = 0;
	while (step.y < file->ord_count)
	{
		step.x = 0;
		while (step.x < file->abs_count)
		{
			if (step.x < file->abs_count - 1)
				ft_bresenham(file, step, ft_right(step));
			if (step.y < file->ord_count - 1)
				ft_bresenham(file, step, ft_down(step));
			step.x++;
		}
		step.y++;
	}
	mlx_put_image_to_window(file->mlx, file->win, file->img.img, 0, 0);
}
