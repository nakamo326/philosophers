#include "philosophers.h"

int	exit_free(t_info *info, t_philo *philos, char *err)
{
	free(info->forks);
	free(info->print);
	free(philos);
	if (err != NULL) {
		printf("%s\n", err);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
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
		if (tmp <= 1 || tmp > INT_MAX)
			return (false);
		info->params[i - 1] = tmp;
		i++;
	}
	if (argc == 5)
		info->params[LIMIT_TIMES_TO_DIE] = -1;
	return (true);
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo *philos;

	if (!parse_arg(&info, argc, argv))
		return (exit_free(NULL, NULL, "Invalid arguments."));
	if (!init_info(&info))
		return (exit_free(&info, NULL, "failed to init infos."));
	philos = init_philos(info);
	if (philos == NULL)
		return (exit_free(&info, philos, "failed to init philos."));
	// start_sims(info, philos);
	// join_philos();
	return (exit_free(&info, philos, NULL));
}
