#include "philosophers.h"

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

int	ft_atoi(const char *nptr)
{
	int	num;

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
	int	tmp;

	if (!(argc == 5 || argc == 6))
		return (false);
	for (int i = 1; i < argc; i++)
	{
		if (ft_strlen(argv[i]) > 10 || !ft_isdigits(argv[i]))
			return (false);
		tmp = ft_atoi(argv[i]);
		if (tmp <= 0 || tmp > INT_MAX)
			return (false);
		info->params[i - 1] = tmp;
	}
	if (argc == 5)
		info->params[LIMIT_TIMES_TO_DIE] = -1;
	return (true);
}
