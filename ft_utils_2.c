#include "fdf.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		i;

	dst = (char *)malloc(sizeof(*dst) * ft_strlen(s1) + 1);
	if (!(dst))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_ptr;

	s_ptr = s;
	while (n-- > 0)
	{
		if (*s_ptr == (const unsigned char)c)
			return ((void *)s_ptr);
		s_ptr++;
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ret;

	ret = ft_memchr(s, c, (ft_strlen(s) + 1));
	return (ret);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	while (n-- > 0)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
