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

void	*count_ticket(void *p) {
	int i;
	t_info	*info;

	info = (t_info *)p;
	// if (info->params[LIMIT_TIMES_TO_DIE] == -1)
	// 	exit(EXIT_SUCCESS);
	i = 0;
	while (i < info->params[NUM_OF_PHILOS])
	{
		sem_wait(info->ticket);
		i++;
	}
	sem_wait(info->print);
	sem_post(info->is_dead);
	return (NULL);
}

void	monitor_dead(t_info *info) {
	int i;
	pthread_t monitor;

	pthread_create(&monitor, NULL, count_ticket, info);
	pthread_detach(monitor);
	sem_wait(info->is_dead);

	i = 0;
	(void)i;
	while(i < info->params[NUM_OF_PHILOS])
	{
		kill(info->procs[i], SIGKILL);
		i++;
	}
}

void	wait_philos(t_info *info)
{
	int	i;
	int	status;

	i = 0;
	while (i < info->params[NUM_OF_PHILOS])
	{
		waitpid(0, &status, 0);
		i++;
	}
	return ;
}
