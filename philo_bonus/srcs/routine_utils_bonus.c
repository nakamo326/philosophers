#include "philosophers_bonus.h"

void	update_lastmeal_time(long time, t_philo *p)
{
	sem_wait(p->info->print);
	p->last_meal_time = time;
	sem_post(p->info->print);
}

long	read_lastmeal_time(t_philo *p)
{
	long	ret;

	sem_wait(p->info->print);
	ret = p->last_meal_time;
	sem_post(p->info->print);
	return (ret);
}
