#include "fdf.h"

static double	ft_percent(double start, double end, double current)
{
	double	distance;
	double	travel;

	travel = current - start;
	distance = end - start;
	if (distance == 0)
		return (1);
	else
		return (travel / distance);
}

int	ft_get_color(t_fdf *file, int value)
{
	double	percent;

	percent = ft_percent(file->min_elevation, file->max_elevation, value);
	if (percent < .2)
		return (BLACK_CURRANT);
	else if (percent < .4)
		return (DARK_CERULEAN);
	else if (percent < .6)
		return (JAVA);
	else if (percent < .8)
		return (FERN);
	else
		return (GORSE);
}

static int	ft_interpolate(int start, int end, double percent)
{
	return ((1 - percent) * start + percent * end);
}

static t_rgb	ft_isolate_rgb(int color)
{
	t_rgb	component;

	component.red = (color >> 16) & 0xFF;
	component.green = (color >> 8) & 0xFF;
	component.blue = color & 0xFF;
	return (component);
}

void	ft_init_color(t_fdf *file)
{
	t_rgb	start_rgb;
	t_rgb	end_rgb;
	t_rgb	new_rgb;
	double	percent;

	if (file->line.start.color == file->line.end.color)
		return ;
	if (ft_is_grad(file->line.start, file->line.end))
		percent = ft_percent(file->line.start.x, file->line.end.x,
				file->line.curr.x);
	else
		percent = ft_percent(file->line.start.y, file->line.end.y,
				file->line.curr.y);
	start_rgb = ft_isolate_rgb(file->line.start.color);
	end_rgb = ft_isolate_rgb(file->line.end.color);
	new_rgb.red = ft_interpolate(start_rgb.red, end_rgb.red, percent);
	new_rgb.green = ft_interpolate(start_rgb.green, end_rgb.green, percent);
	new_rgb.blue = ft_interpolate(start_rgb.blue, end_rgb.blue, percent);
	file->line.curr.color = ((new_rgb.red << 16) | (new_rgb.green << 8)
			| new_rgb.blue);
}
