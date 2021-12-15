#include "philosophers_tmp.h"

void	*doctor_routine(void *philo)
{
	t_philo	*p;
	long	now;
	long	lasttime;

	p = (t_philo *)philo;
	while (true)
	{
		usleep(1000);
		now = get_time();
		lasttime = read_lastmeal_time(p);
		if (now - lasttime >= p->info->params[TIME_TO_DIE])
		{
			sem_wait(p->info->print);
			printf("%ld %d died\n", now, p->index);
			sem_post(p->info->is_dead);
			exit(EXIT_SUCCESS);
		}
		sem_post(p->info->print);
	}
	return (NULL);
}
