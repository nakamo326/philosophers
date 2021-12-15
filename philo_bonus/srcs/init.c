#include "philosophers_bonus.h"

int	exit_free(t_info *info, t_philo *philo, char *err)
{
	if (info != NULL)
	{
		free(info->pids);
	}
	free(philo);
	if (err != NULL)
	{
		printf("%s\n", err);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

bool	init_info(t_info *info)
{
	info->pids = malloc(sizeof(pid_t) * info->params[NUM_OF_PHILOS]);
	if (info->pids == NULL)
		return (false);
	info->forks = sem_open(SEM_FORK, O_CREAT | O_EXCL, S_IRWXU, info->params[NUM_OF_PHILOS]);
	info->print = sem_open(SEM_PRINT, O_CREAT | O_EXCL, S_IRWXU, 1);
	if (info->forks == SEM_FAILED || info->print == SEM_FAILED)
		return (false);
	info->is_dead = false;
	info->fullfill_num = 0;
	return (true);
}

t_philo	*init_philos(t_info *info)
{
	t_philo	*philos;

	philos = malloc(sizeof(t_philo));
	philos->info = info;
	philos->times_of_finished_meal = 0;
	return (philos);
}
