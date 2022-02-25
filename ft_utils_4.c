#include "fdf.h"

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

int	ft_atoi(const char *str)
{
	int				i;
	long long int	nbr;
	long long int	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (ft_isdigit(str[i]) && str[i])
	{
		nbr = nbr * 10 + (str[i++] - '0');
		if (nbr < 0)
			return ((sign + 1) / -2);
	}
	return ((int)(nbr * sign));
}

size_t	ft_numlen(long long n, int base)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	tmp;

	tmp = n;
	if (n < 0)
		tmp = -n;
	len = ft_numlen(tmp, 10);
	if (n < 0)
		len = ft_numlen(tmp, 10) + 1;
	str = (char *)malloc(sizeof(*str) * len + 1);
	if (!(str))
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (tmp)
	{
		str[len--] = tmp % 10 + '0';
		tmp /= 10;
	}
	return (str);
}
