#include "philosophers.h"

void	update_lastmeal_time(long time, t_philo *p)
{
	pthread_mutex_lock(&p->access_to_last_meal);
	p->last_meal_time = time;
	pthread_mutex_unlock(&p->access_to_last_meal);
}

long	read_lastmeal_time(t_philo *p)
{
	long	ret;

	pthread_mutex_lock(&p->access_to_last_meal);
	ret = p->last_meal_time;
	pthread_mutex_unlock(&p->access_to_last_meal);
	return (ret);
}