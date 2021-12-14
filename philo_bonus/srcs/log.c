#include "philosophers_bonus.h"

long	output_log(t_philo *p, const char *str)
{
	long			time;

	time = get_time();
	sem_wait(p->info->print);
	if (!p->info->is_dead)
	{
		printf("%ld %d%s\n", time, p->index, str);
	}
	sem_post(p->info->print);
	return (time);
}
