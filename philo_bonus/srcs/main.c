#include "philosophers_bonus.h"

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philo;

	if (!parse_arg(&info, argc, argv))
		return (exit_free(NULL, NULL, "Invalid arguments."));
	if (!init_info(&info))
		return (exit_free(&info, NULL, "failed to init infos."));
	philo = init_philo(&info);
	if (philo == NULL)
		return (exit_free(&info, philo, "failed to init philo."));
	start_sims(philo);
	join_philos(&info);
	return (exit_free(&info, philo, NULL));
}
