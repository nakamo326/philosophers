#include "philosophers.h"

long	output_log(t_philo *p, t_log_i log_i)
{
	const char		*log_str[5] = {" has taken a fork",
	" is eating", " is sleeping", " is thinking", " died"};
	long			time;

	time = get_time();
	pthread_mutex_lock(&p->info->print);
	if (!p->info->is_dead
		&& !(p->info->fullfill_num == p->params[NUM_OF_PHILOS]))
	{
		printf("%ld %d%s\n", time, p->index, log_str[log_i]);
	}
	pthread_mutex_unlock(&p->info->print);
	return (time);
}
