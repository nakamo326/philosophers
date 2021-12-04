#include "philosophers.h"

int	free_info(t_info info, t_philo *philos, int ret)
{
	free(philos);
	free(info.forks);
	free(info.print);
	return (ret);
}

int	print_error(char *msg)
{
	printf("%s\n", msg);
	return (EXIT_FAILURE);
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
	return (true);
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo *philos;

	if (!parse_arg(&info, argc, argv))
		return (print_error("Invalid arguments."));
	if (!init_info(&info))
	{
		print_error("failed to init infos.");
		return (free_info(info, philos, EXIT_FAILURE));
	}
	init_philos(philos, info);
	start_sims(info, philos);
	
	return (free_info(info, philos, EXIT_SUCCESS));
}
