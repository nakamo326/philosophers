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
	}
	return (true);
}


//need to fix
void	join_philos(t_philo *philo)
{
	int	i;
	int	num;

	i = 0;
	num = philo->info->params[NUM_OF_PHILOS];
	while (i < num)
	{
		//wait
		pthread_join(philo[i].doctor, NULL);
		i++;
	}
	return ;
}
