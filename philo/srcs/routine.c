#include "philosophers.h"

void	*philo_routine(void *philo)
{
	int		i;
	int		limit_times;
	t_philo	*p;

	p = (t_philo *)philo;
	i = 0;
	limit_times = p->params[LIMIT_TIMES_TO_DIE];
	while ((limit_times == -1 || i < limit_times) && !is_dead(p) && !is_finished(p))
	{
		shake_forks(p);
		eat_meal(p);
		release_forks(p);
		sleep_well(p);
	}
	return (p);
}

void	*doctor_routine(void *philo)
{
	t_philo *p;
	long	now;
	long	lasttime;

	p = philo;
	while (!is_dead(p) && !is_finished(p))
	{
		my_usleep(500);
		now = get_time();
		lasttime = read_lastmeal_time(p);
		if (now - lasttime >= p->params[TIME_TO_DIE]) {
			pthread_mutex_lock(&p->info->access_to_is_dead);
			p->info->is_dead = true;
			output_log(p->print, p->index, DIED);
			pthread_mutex_unlock(&p->info->access_to_is_dead);
		}
	}
	return (p);
}
