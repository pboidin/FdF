#include "fdf.h"

int	ft_open_file(t_fdf *file, char *name)
{
	int	fd;

	fd = open(name, O_RDONLY);
	if (fd == -1)
		ft_exit_failed(file, "Could not open .fdf file");
	return (fd);
}

static void	ft_values_checker(t_fdf *file, t_gnl gnl)
{
	int		i;
	char	*cmp;

	i = 0;
	while (gnl.line[i])
	{
		while (gnl.line[i] && ft_isspace(gnl.line[i]))
			i++;
		cmp = ft_itoa(ft_atoi(&gnl.line[i]));
		if (!cmp)
			ft_close(file, gnl.fd, gnl.line, "Memory Error");
		if (ft_memcmp(cmp, &gnl.line[i], ft_strlen(cmp) != 0))
		{
			ft_free(cmp);
			if (!ft_isdigit(gnl.line[i]))
				ft_close(file, gnl.fd, gnl.line, "Invalid map");
			else
				ft_close(file, gnl.fd, gnl.line, "Value Int");
		}
		i += ft_strlen(cmp);
		ft_free(cmp);
		while ((gnl.line[i] == ',' || ft_isalnum(gnl.line[i])) && gnl.line[i])
			i++;
	}
}

static int	ft_abs_counter(t_fdf *file, int fd, char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		while (ft_isspace(line[i]) || line[i] == '-')
			i++;
		if (ft_isdigit(line[i]))
			count++;
		else
			ft_close(file, fd, line, "Invalid map format");
		while (ft_isdigit(line[i]))
			i++;
		while ((line[i] == ',' || ft_isalnum(line[i])) && line[i])
			i++;
		while (ft_isspace(line[i]))
			i++;
		if (line[i] != '\0' && !ft_isdigit(line[i]) && line[i] != '-')
			ft_close(file, fd, line, "Invalid item in map");
	}
	return (count);
}

void	ft_map_reader(t_fdf *file)
{
	t_gnl	gnl;

	gnl.line = NULL;
	gnl.fd = ft_open_file(file, file->filemap);
	gnl.ret = ft_gnl(gnl.fd, &gnl.line);
	if (gnl.ret == -1)
		ft_close(file, gnl.fd, gnl.line, "Memory allocation error");
	while (gnl.ret == 1)
	{
		ft_values_checker(file, gnl);
		file->ord_count++;
		if (file->abs_count != 0
			&& file->abs_count != ft_abs_counter(file, gnl.fd, gnl.line))
			ft_close(file, gnl.fd, gnl.line, "Invalid map widths");
		file->abs_count = ft_abs_counter(file, gnl.fd, gnl.line);
		ft_free(gnl.line);
		gnl.ret = ft_gnl(gnl.fd, &gnl.line);
		if (gnl.ret == -1)
			ft_close(file, gnl.fd, gnl.line, "Memory error");
	}
	ft_free(gnl.line);
	close(gnl.fd);
}
