#include "philosophers_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

bool	ft_isdigits(char *s)
{
	if (!s || !*s)
		return (false);
	while (*s)
	{
		if (*s < '0' || *s > '9')
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

bool	parse_arg(t_info *info, int argc, char **argv)
{
	int			i;
	long long	tmp;

	if (!(argc == 5 || argc == 6))
		return (false);
	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 10 || !ft_isdigits(argv[i]))
			return (false);
		tmp = ft_atoll(argv[i]);
		if (tmp <= 0 || tmp > INT_MAX)
			return (false);
		info->params[i - 1] = tmp;
		i++;
	}
	if (argc == 5)
		info->params[LIMIT_TIMES_TO_DIE] = -1;
	return (true);
}
