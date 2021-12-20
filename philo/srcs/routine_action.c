#include "philosophers.h"

void	shake_forks(t_philo *p)
{
	if (p->index % 2 == 1)
	{
		pthread_mutex_lock(p->right);
		output_log(p, TAKEN_FORK);
		pthread_mutex_lock(p->left);
		output_log(p, TAKEN_FORK);
	}
	else
	{
		pthread_mutex_lock(p->left);
		output_log(p, TAKEN_FORK);
		pthread_mutex_lock(p->right);
		output_log(p, TAKEN_FORK);
	}
}

void	release_forks(t_philo *p)
{
	pthread_mutex_unlock(p->right);
	pthread_mutex_unlock(p->left);
}

void	eat_meal(t_philo *p)
{
	update_lastmeal_time(output_log(p, EATING), p);
	my_usleep(p->info->params[TIME_TO_EAT]);
	p->times_of_finished_meal++;
	if (p->times_of_finished_meal == p->info->params[LIMIT_TIMES_TO_DIE])
	{
		pthread_mutex_lock(&p->info->print);
		p->info->fullfill_num++;
		pthread_mutex_unlock(&p->info->print);
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
	if (p->info->is_odd && p->index % 2 == 1)
		my_usleep(10);
}
