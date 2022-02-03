#include "fdf.h"

int	ft_get_height(char *file)
{
	char	*line;
	int	fd;
	int	height;

	height = 0;
	fd = open(file, O_RDONLY, 0);
	while (ft_get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int	ft_get_width(char *file)
{
	char	*line;
	int	fd;
	int	width;

	width = 0;
	fd = open(file, O_RDONLY, 0);
	ft_get_next_line(fd, &line);
	width = ft_count_word(line, ' ');
	close(fd);
	return (width);
}

void	ft_matrix(int *data, char *line)
{
	char	**str;
	int	i;

	str = ft_split(line, ' ');
	i = 0;
	while (str[i])
	{
		data[i] = ft_atoi(str[i]);
		free(str[i]);
		i++;
	}
}

void	ft_file_reader(char *file, s_fdf *data)
{
	char	*line;
	int	fd;
	int	i;

	data->height = ft_get_height(file);
	data->width = ft_get_width(file);

	data->alt = (int**)malloc(sizeof(int*) * (data->height + 1));
	while (i <= data->height)
		data->alt[i++] = (int*)malloc(sizeof(int) * (data->width + 1));
	fd = open(file, O_RDONLY, 0);
	i = 0;
	while (ft_get_next_line(fd, &line))
	{
		ft_matrix(data->alt[i], line);
		free(line);
		i++;
	}
	close(fd);
	data->alt[i] = NULL;
}
