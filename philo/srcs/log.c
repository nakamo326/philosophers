#include "philosophers.h"

long	output_log(t_philo *p, const char *str)
{
	long			time;

	time = get_time();
	if (!is_dead(p) && !is_fullfilled(p))
	{
		pthread_mutex_lock(&p->info->print);
		printf("%ld %d%s\n", time, p->index, str);
		pthread_mutex_unlock(&p->info->print);
	}
	return (time);
}
