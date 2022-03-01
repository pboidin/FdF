/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:36:36 by piboidin          #+#    #+#             */
/*   Updated: 2022/03/01 14:34:53 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libraries/minilibx-linux/mlx.h"
# include "fdf_key_macros.h"
# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>

# define DEFAULT_ZOOM 10
# define WID 1000
# define HGHT 1000
# define BUFFER_SIZE 1024
# define MAX_FD 10
# define TAN_30_DEGREES .577

# define BLACK_CURRANT 0x533A71
# define DARK_CERULEAN 0x6184D8
# define JAVA 0x50C5B7
# define FERN 0xCEC5B
# define GORSE 0xF0F465

# define KEY_PRESS 2
# define KEY_PRESS_MASK 1
# define WIN_DSTRY 17
# define WIN_DSTRY_MASK 131072

typedef struct s_gnl
{
	char	*line;
	int		fd;
	int		ret;
}				t_gnl;

typedef struct s_point
{
	int		x;
	int		y;
	double	value;
	int		color;
}				t_point;

typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}				t_rgb;

typedef struct s_line
{
	t_point	start;
	t_point	curr;
	t_point	end;
	t_point	delta;
	int		diff;	
}				t_line;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		end;
}				t_img;

typedef struct s_elev
{
	double	value;
	int		color;
}				t_elev;

typedef struct s_fdf
{
	char		projection;
	char		*filemap;
	double		x_rot;
	double		y_rot;
	double		z_rot;
	int			abs;
	int			abs_count;
	int			ord;
	int			ord_count;
	int			grid_zoom;
	int			elevation_zoom;
	int			x_shift;
	int			y_shift;
	int			yi;
	int			xi;
	int			min_elevation;
	int			max_elevation;
	int			win_width;
	int			win_hight;
	t_elev		**map;
	t_img		img;
	t_line		line;
	void		*mlx;
	void		*win;
}				t_fdf;

bool			ft_bounds_error(t_fdf *file, t_point curr);
bool			ft_is_grad(t_point start, t_point end);

char			*ft_itoa(int n);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);

int				ft_abs(int num);
int				ft_atoi(const char *str);
int				ft_exit_successful(t_fdf *file);
int				ft_get_color(t_fdf *file, int value);
int				ft_gnl(int fd, char **line);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isdigit(int c);
int				ft_isspace(int c);
int				ft_key_press(int keycode, t_fdf *file);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_open_file(t_fdf *file, char *name);

size_t			ft_find_char(const char *s, int c);
size_t			ft_numlen(long long n, int base);
size_t			ft_strlen(const char *s);

void			ft_bresenham(t_fdf *file, t_point start, t_point end);
void			ft_close(t_fdf *file, int fd, char *line, char *err_msg);
void			ft_draw(t_fdf *file);
void			ft_error_exit(char *mem, char *msg);
void			ft_exit_failed(t_fdf *file, char *error_message);
void			ft_failed_exit(char *message, char *memory);
void			ft_free(void *ptr);
void			ft_init_color(t_fdf *file);
void			ft_init_map(t_fdf *file);
void			ft_init_line(t_fdf *file);
void			ft_init_point(t_fdf *file, t_point *dest, t_point *src);
void			ft_iso_conv(int *x, int *y, int z);
void			ft_mod_projection(int keycode, t_fdf *file);
void			ft_mod_transformation(int keycode, t_fdf *file);
void			ft_mod_translation(int keycode, t_fdf *file);
void			ft_mod_zoom(int keycode, t_fdf *file);
void			ft_map_reader(t_fdf *file);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_x_rot(int *axis, double *value, double rot);
void			ft_y_rot(int *axis, double *value, double rot);
void			ft_z_rot(int *x, int *y, double rot);

void			*ft_memchr(const void *s, int c, size_t n);

#endif
