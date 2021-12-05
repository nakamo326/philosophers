#include "philosophers.h"

bool	is_dead(t_philo *p)
{
	bool	ret;

	pthread_mutex_lock(&p->info->access_to_is_dead);
	ret = p->info->is_dead;
	pthread_mutex_unlock(&p->info->access_to_is_dead);
	return (ret);
}

bool	is_fullfilled(t_philo *p)
{
	bool	ret;

	pthread_mutex_lock(&p->info->access_to_fullfill);
	ret = (p->info->fullfill_num == p->params[NUM_OF_PHILOS]);
	pthread_mutex_unlock(&p->info->access_to_fullfill);
	return (ret);
}

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
