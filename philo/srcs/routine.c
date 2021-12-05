#include "philosophers.h"

void	*philo_routine(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	update_lastmeal_time(get_time(), p);
	if (p->info->params[NUM_OF_PHILOS] == 1)
	{
		output_log(p, TAKEN_FORK);
		return (NULL);
	}
	while (!is_dead(p) && !is_fullfilled(p))
	{
		shake_forks(p);
		eat_meal(p);
		release_forks(p);
		sleep_well(p);
	}
	return (NULL);
}

void	*doctor_routine(void *philo)
{
	t_philo	*p;
	long	now;
	long	lasttime;

	p = (t_philo *)philo;
	while (!is_dead(p) && !is_fullfilled(p))
	{
		usleep(1000);
		now = get_time();
		lasttime = read_lastmeal_time(p);
		if (now - lasttime >= p->params[TIME_TO_DIE])
		{
			output_log(p, DIED);
			pthread_mutex_lock(&p->info->access_to_is_dead);
			p->info->is_dead = true;
			pthread_mutex_unlock(&p->info->access_to_is_dead);
		}
	}
	return (NULL);
}
