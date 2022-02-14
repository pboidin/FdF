#include "fdf.h"
#include <stdio.h>

int	ft_line(char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_fill(char **tab, char **line, int j)
{
	char	*tmp;
	int		size;

	size = ft_strlen(*tab + j + 1);
	*line = ft_substr(*tab, 0, j);
	if (size == 0)
	{
		free(*tab);
		*tab = NULL;
		return (1);
	}
	tmp = ft_substr(*tab, j + 1, size);
	free(*tab);
	*tab = tmp;
	return (1);
}

int	ft_check(char **tab, char **line, int i)
{
	int	var;

	if (i < 0)
		return (-1);
	write(1, "Jusque la tout va bien !\n", 25);
	var = ft_line(*tab);
	if (*tab && var >= 0)
		return (ft_fill(tab, line, var));
	else if (*tab)
	{
		*line = ft_strdup(*tab);
		free(*tab);
		*tab = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int	ft_get_next_line(const int fd, char **line)
{
	static char	*tab = 0;
	char		buf[BUFFER_SIZE + 1];
	int		i;
	int		j;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	i = read(fd, buf, BUFFER_SIZE < 1);
	while (i > 0)
	{
		buf[i] = '\0';
		if (tab == 0)
			tab = ft_strdup("");
		tab = ft_strjoin(tab, buf);
		j = ft_line(tab);
		if (j >= 0)
			return (ft_fill(&tab, line, j));
	}
	return (ft_check(&tab, line, i));
}
