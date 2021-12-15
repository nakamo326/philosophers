#include "philosophers_tmp.h"

void	shake_forks(t_philo *p)
{
	sem_wait(p->info->forks);
	output_log(p, TAKEN_FORK);
	sem_wait(p->info->forks);
	output_log(p, TAKEN_FORK);
}

void	release_forks(t_philo *p)
{
	sem_post(p->info->forks);
	sem_post(p->info->forks);
}

void	eat_meal(t_philo *p)
{
	update_lastmeal_time(output_log(p, EATING), p);
	my_usleep(p->info->params[TIME_TO_EAT]);
	p->times_of_finished_meal++;
	if (p->times_of_finished_meal == p->info->params[LIMIT_TIMES_TO_DIE])
	{
		sem_post(p->info->ticket);
	}
}

void	sleep_well(t_philo *p)
{
	output_log(p, SLEEPING);
	my_usleep(p->info->params[TIME_TO_SLEEP]);
}

void	think_about_truth(t_philo *p)
{
	output_log(p, THINKING);
}
