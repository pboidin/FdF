/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:39:03 by piboidin          #+#    #+#             */
/*   Updated: 2022/02/28 15:39:05 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_init_mlx(t_fdf *file)
{
	file->mlx = mlx_init();
	if (!file->mlx)
		ft_error_exit("Connection failed", NULL);
	file->win = mlx_new_window(file->mlx,
			file->win_width, file->win_hight, "fdf");
	if (!file->win)
		ft_exit_failed(file, "Could not create window");
	file->img.img = mlx_new_image(file->mlx, file->win_width, file->win_hight);
	if (!file->img.img)
		ft_exit_failed(file, "Could not create image");
	file->img.addr = mlx_get_data_addr(file->img.img,
			&file->img.bpp, &file->img.len, &file->img.end);
}

static void	ft_struct_init(t_fdf *file)
{
	file->projection = 'i';
	file->x_rot = 0;
	file->y_rot = 0;
	file->z_rot = 0;
	file->abs = 0;
	file->abs_count = 0;
	file->ord = 0;
	file->ord_count = 0;
	file->grid_zoom = DEFAULT_ZOOM;
	file->elevation_zoom = DEFAULT_ZOOM;
	file->x_shift = 0;
	file->y_shift = 0;
	file->min_elevation = 0;
	file->max_elevation = 0;
	file->win_width = WID;
	file->win_hight = HGHT;
	file->img.img = NULL;
	file->img.addr = NULL;
	file->mlx = NULL;
	file->win = NULL;
	ft_map_reader(file);
	ft_init_mlx(file);
	ft_init_map(file);
}

static void	ft_checker(t_fdf *file, int argc, char **argv)
{
	char	buf[1];
	int		fd;
	int		r;
	int		start;

	if (argc > 2)
		ft_error_exit(NULL, "Too many arguments");
	else if (argc < 2)
		ft_error_exit(NULL, "Please select one file .fdf to read");
	start = ft_strlen(argv[1]) - 4;
	if (ft_memcmp(&argv[1][start], ".fdf", 4) != 0)
		ft_error_exit(NULL, "Second arguments need to be a .fdf file!");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error_exit(NULL, "Could not open .fdf file");
	r = read(fd, buf, 1);
	close(fd);
	if (r == -1)
		ft_error_exit(NULL, "Check .fdf file is correct type of file");
	file->filemap = argv[1];
}

int	main(int argc, char **argv)
{
	t_fdf	file;

	ft_checker(&file, argc, argv);
	ft_struct_init(&file);
	ft_draw(&file);
	mlx_hook(file.win, KEY_PRESS, KEY_PRESS_MASK, &ft_key_press, &file);
	mlx_hook(file.win, WIN_DSTRY, WIN_DSTRY_MASK, &ft_exit_successful, &file);
	mlx_loop(file.mlx);
}
