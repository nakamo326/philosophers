#include "philosophers.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

bool	ft_isdigits(char *s)
{
	if (!s || !*s)
		return (false);
	while (*s)
	{
		if (*s <= 48 && *s >= 57)
			return (false);
		s++;
	}
	return (true);
}

long long	ft_atoll(const char *nptr)
{
	long long	num;

	num = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = num * 10 + *nptr - '0';
		nptr++;
	}
	return (num);
}
