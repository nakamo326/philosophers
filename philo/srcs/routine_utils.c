#include "philosophers.h"

long	get_time(void)
{
	struct timeval	tp;
	long			ms;

	gettimeofday(&tp, NULL);
	ms = tp.tv_sec * 1000;
	ms += tp.tv_usec / 1000;
	return (ms);
}

void	my_usleep(int ms)
{
	long	start;

	//check is dead
	start = get_time();
	while (get_time() - start < ms)
	{
		usleep(1000);
	}
}

long	output_log(t_philo *p, t_log_i log_i)
{
	const char		*log_str[5] = {" has taken a fork",
	" is eating", " is sleeping", " is thinking", " died"};
	long			time;

	time = get_time();
	if (!is_dead(p) && !is_fullfilled(p))
	{
		pthread_mutex_lock(p->print);
		printf("%ld %d%s\n", time, p->index, log_str[log_i]);
		pthread_mutex_unlock(p->print);
	}
	return (time);
}

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
