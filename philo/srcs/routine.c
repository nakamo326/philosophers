#include "philosophers.h"

void	*philo_routine(void *philo)
{
	int		i;
	int		limit_times;
	t_philo	*p;

	p = (t_philo *)philo;
	i = 0;
	limit_times = p->params[LIMIT_TIMES_TO_DIE];
	while ((limit_times == -1 || i < limit_times) && !is_dead(p))
	{
		//check is_dead before every action
		shake_forks(p);
		eat_meal(p);
		sleep_well(p->params[TIME_TO_SLEEP]);
		think_about_truth(p);
	}
	return (p);
}

void	*doctor_routine(void *philo)
{
	t_philo *p;
	long	now;

	p = philo;
	while (!is_dead(p) || !is_finished(p))
	{
		my_usleep(500);
		pthread_mutex_lock(&p->access_to_last_meal);
		now = get_time();
		if (now - p->last_meal_time > p->params[TIME_TO_DIE]) {
			pthread_mutex_lock(&p->access_to_is_dead);
			p->is_dead = true;
			pthread_mutex_unlock(&p->access_to_is_dead);
		}
		pthread_mutex_unlock(&p->access_to_last_meal);
	}
}
