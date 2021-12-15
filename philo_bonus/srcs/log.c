#include "philosophers_bonus.h"

long	output_log(t_philo *p, const char *str)
{
	long			time;

	time = get_time();
	pthread_mutex_lock(&p->info->print);
	if (!p->info->is_dead
		&& !(p->info->fullfill_num == p->info->params[NUM_OF_PHILOS]))
	{
		printf("%ld %d%s\n", time, p->index, str);
	}
	pthread_mutex_unlock(&p->info->print);
	return (time);
}
