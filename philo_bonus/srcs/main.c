#include "philosophers_bonus.h"

void	unlink_all_sem() {
	sem_unlink(SEM_FORM);
	sem_unlink(SEM_PRINT);
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
	join_philos(&info);
	unlink_all_sem();
	return (exit_free(&info, philo, NULL));
}
