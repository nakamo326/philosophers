#include "philosophers_bonus.h"

int	exit_free(t_info *info, t_philo *philo, char *err)
{
	if (info != NULL)
	{
		free(info->procs);
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
	info->procs = malloc(sizeof(pid_t) * info->params[NUM_OF_PHILOS]);
	if(info->procs == NULL)
		return (false);
	info->forks = sem_open(SEM_FORK, O_CREAT | O_EXCL, S_IRWXU, info->params[NUM_OF_PHILOS]);
	if (info->forks == SEM_FAILED)
		return (false);
	info->print = sem_open(SEM_PRINT, O_CREAT | O_EXCL, S_IRWXU, 1);
	if (info->print == SEM_FAILED)
		return (false);
	if (info->params[LIMIT_TIMES_TO_DIE] != -1)
	{
		info->ticket = sem_open(SEM_TICKET,O_CREAT | O_EXCL, S_IRWXU,
			info->params[NUM_OF_PHILOS]);
		if (info->ticket == SEM_FAILED)
			return (false);
	}
	info->is_dead = false;
	return (true);
}

t_philo	*init_philo(t_info *info)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	philo->info = info;
	philo->times_of_finished_meal = 0;
	return (philo);
}
