#include "philosophers.h"

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
		info->params[i] = tmp;
		i++;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (!parse_arg(&info, argc, argv))
	{
		printf("Invalid arguments.\n");
		return (EXIT_FAILURE);
	}
	start_sims(info);
	return (EXIT_SUCCESS);
}
