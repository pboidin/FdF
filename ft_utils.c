#include "fdf.h"

void	ft_free(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

void	ft_putendl_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		ft_putchar_fd(*s++, fd);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_error_exit(char *mem, char *msg)
{
	if (mem)
	{
		ft_free(mem);
		mem = NULL;
	}
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
