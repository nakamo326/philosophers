#include "philosophers_bonus.h"

void	*count_ticket(void *p) {
	int i;
	t_info	*info;

	info = (t_info *)p;

	i = 0;
	while (i < info->params[NUM_OF_PHILOS])
	{
		sem_wait(info->ticket);
		i++;
	}
	sem_post(info->bomb);
	return (NULL);
}

bool	monitor_dead(t_info *info) {
	int			i;
	pthread_t	monitor;

	if (info->params[LIMIT_TIMES_TO_DIE] != -1) {
		if (pthread_create(&monitor, NULL, count_ticket, info))
			return (false);
		pthread_detach(monitor);
	}
	sem_wait(info->bomb);
	i = 0;
	while(i < info->params[NUM_OF_PHILOS])
	{
		kill(info->procs[i], SIGKILL);
		i++;
	}
	return (true);
}
