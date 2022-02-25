#include "fdf.h"

static void	ft_pixel_put(t_fdf *file, t_point curr)
{
	char	*dest;
	int		location;

	location = curr.y * file->img.len + curr.x * (file->img.bpp / 8);
	dest = file->img.addr + location;
	*(unsigned int *)dest = curr.color;
}

static void	ft_grad_slope(t_fdf *file)
{
	while (file->line.curr.x <= file->line.end.x)
	{
		if (!(ft_bounds_error(file, file->line.curr)))
		{
			ft_init_color(file);
			ft_pixel_put(file, file->line.curr);
		}
		if (file->line.diff > 0)
		{
			file->line.curr.y = file->line.curr.y + file->yi;
			file->line.diff += (2 * (file->line.delta.y - file->line.delta.x));
		}
		else
			file->line.diff = file->line.diff + 2 * file->line.delta.y;
		file->line.curr.x++;
	}
}

static void	ft_steep_slope(t_fdf *file)
{
	while (file->line.curr.y <= file->line.end.y)
	{
		if (!(ft_bounds_error(file, file->line.curr)))
		{
			ft_init_color(file);
			ft_pixel_put(file, file->line.curr);
		}
		if (file->line.diff > 0)
		{
			file->line.curr.x = file->line.curr.x + file->xi;
			file->line.diff += (2 * (file->line.delta.x - file->line.delta.y));
		}
		else
			file->line.diff = file->line.diff + 2 * file->line.delta.x;
		file->line.curr.y++;
	}
}

static void	ft_reverse(t_fdf *file)
{
	t_point	tmp;

	tmp = file->line.start;
	file->line.start = file->line.end;
	file->line.end = tmp;
}

void	ft_bresenham(t_fdf *file, t_point start, t_point end)
{
	ft_init_point(file, &file->line.start, &start);
	ft_init_point(file, &file->line.end, &end);
	if (ft_is_grad(file->line.start, file->line.end))
	{
		if (file->line.start.x > file->line.end.x)
			ft_reverse(file);
		ft_init_line(file);
		ft_grad_slope(file);
	}
	else
	{
		if (file->line.start.y > file->line.end.y)
			ft_reverse(file);
		ft_init_line(file);
		ft_steep_slope(file);
	}
}
