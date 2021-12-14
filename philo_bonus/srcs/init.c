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
	info->forks = sem_open("forks", O_CREAT, O_RDWR,info->params[NUM_OF_PHILOS]);
	if (info->forks == SEM_FAILED)
		return (false);
	info->print = sem_open("print", O_CREAT, O_RDWR,info->params[NUM_OF_PHILOS]);
	if (info->print == SEM_FAILED)
		return (false);
	info->is_dead = false;
	info->fullfill_num = 0;
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
