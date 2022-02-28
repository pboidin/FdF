/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:36:55 by piboidin          #+#    #+#             */
/*   Updated: 2022/02/28 15:36:57 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

bool	ft_is_grad(t_point start, t_point end)
{
	return (ft_abs(end.y - start.y) < ft_abs(end.x - start.x));
}

void	ft_x_rot(int *axis, double *val, double rot)
{
	int		tmp_axis;
	double	tmp_val;

	tmp_axis = *axis;
	tmp_val = *val;
	*axis = cos(rot) * tmp_axis - sin(rot) * tmp_val;
	*val = sin(rot) * tmp_axis + cos(rot) * tmp_val;
}

void	ft_y_rot(int *axis, double *val, double rot)
{
	int		tmp_axis;
	double	tmp_val;

	tmp_axis = *axis;
	tmp_val = *val;
	*axis = cos(rot) * tmp_axis - sin(rot) * tmp_val;
	*val = -sin(rot) * tmp_axis + cos(rot) * tmp_val;
}

void	ft_z_rot(int *x, int *y, double rot)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = *x;
	tmp_y = *y;
	*x = cos(rot) * tmp_x - sin(rot) * tmp_y;
	*y = sin(rot) * tmp_x + cos(rot) * tmp_y;
}
