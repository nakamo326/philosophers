#include "philosophers_bonus.h"

void	unlink_all_sem() {
	sem_unlink(SEM_FORK);
	sem_unlink(SEM_PRINT);
	sem_unlink(SEM_TICKET);
	sem_unlink(SEM_DEAD);
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philo;

	unlink_all_sem();
	if (!parse_arg(&info, argc, argv))
		return (exit_free(NULL, NULL, "Invalid arguments."));
	if (!init_info(&info))
		return (exit_free(&info, NULL, "failed to init infos."));
	philo = init_philo(&info);
	if (philo == NULL)
		return (exit_free(&info, philo, "failed to init philo."));
	start_sims(philo);
	monitor_dead(&info);
	wait_philos(&info);
	unlink_all_sem();
	return (exit_free(&info, philo, NULL));
}
