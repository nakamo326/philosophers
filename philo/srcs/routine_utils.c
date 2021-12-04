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

void	output_log(pthread_mutex_t *print, int p_num, t_log_i log_i)
{
	const char		*log_str[5] = {" has taken a fork",
	" is eating", " is sleeping", " is thinking", " died"};

	//check is dead
	pthread_mutex_lock(print);
	printf("%ld %d%s\n", get_time(), p_num, log_str[log_i]);
	pthread_mutex_unlock(print);
}


bool	is_dead(t_philo *p)
{
	bool	ret;

	pthread_mutex_lock(&p->access_to_is_dead);
	ret = p->is_dead;
	pthread_mutex_unlock(&p->access_to_is_dead);
	return (ret);
}

bool	is_finished(t_philo *p)
{
	bool	ret;

	pthread_mutex_lock(&p->access_to_is_finished);
	ret = p->is_finished;
	pthread_mutex_unlock(&p->access_to_is_finished);
	return (ret);
}
