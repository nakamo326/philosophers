#include "philosophers_bonus.h"

bool	start_sims(t_philo *philo)
{
	int		i;

	i = 0;
	while (i < philo->info->params[NUM_OF_PHILOS])
	{
		philo->index = i + 1;
		philo->info->pids[i] = fork();
		if (philo->info->pids[i] == -1)
			return (false);
		if (philo->info->pids[i] == 0)
		{
			philo_routine(philo);
		}
		i++;
	}
	return (true);
}

void	join_philos(t_info *info)
{
	int	i;
	int status;

	i = 0;
	while (i < info->params[NUM_OF_PHILOS])
	{
		waitpid(0, &status, 0);
		i++;
	}
	return ;
}
