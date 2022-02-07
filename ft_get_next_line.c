#include "fdf.h"

int	ft_get_next_line(const int fd, char **line)
{
	static char	*tab = 0;
	char		buf[BUFFER_SIZE + 1]
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
	return (ft_check(&tab, line, i);
}
