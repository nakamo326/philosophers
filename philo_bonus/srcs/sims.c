#include "philosophers_bonus.h"

bool	start_sims(t_philo *philo)
{
	int		i;

	i = 0;
	while (i < philo->info->params[NUM_OF_PHILOS])
	{
		philo->index = i + 1;
		philo->info->procs[i] = fork();
		if (philo->info->procs[i] == -1)
			return (false);
		if (philo->info->procs[i] == 0) {
			philo_routine(philo);
		}
		i++;
	}
	return (true);
}

void	count_ticket(t_info *info) {
	int i;

	if (info->params[LIMIT_TIMES_TO_DIE] == -1)
		return;
	i = 0;
	while (i < info->params[NUM_OF_PHILOS])
	{
		sem_wait(info->ticket);
		i++;
	}
	i = 0;
	while(i < info->params[NUM_OF_PHILOS])
	{
		kill(info->procs[i], SIGINT);
		i++;
	}
}

void	join_philos(t_info *info)
{
	int	i;
	int	status;

	i = 0;
	while (i < info->params[NUM_OF_PHILOS])
	{
		waitpid(info->procs[i], &status, 0); //check
		i++;
	}
	return ;
}
