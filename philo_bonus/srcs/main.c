#include "philosophers_bonus.h"

void	unlink_all_sem() {
	sem_unlink(SEM_FORK);
	sem_unlink(SEM_PRINT);
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philos;

	unlink_all_sem();
	if (!parse_arg(&info, argc, argv))
		return (exit_free(NULL, NULL, "Invalid arguments."));
	if (!init_info(&info))
		return (exit_free(&info, NULL, "failed to init infos."));
	philos = init_philos(&info);
	if (philos == NULL)
		return (exit_free(&info, philos, "failed to init philos."));
	start_sims(philos);
	join_philos(&info);
	unlink_all_sem();
	return (exit_free(&info, philos, NULL));
}
