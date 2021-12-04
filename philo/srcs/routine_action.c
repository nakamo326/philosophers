#include "philosophers.h"

void	shake_forks(t_philo *p)
{
	if (!is_dead(p))
	{
		pthread_mutex_lock(p->right);
		output_log(p->print, p->index, TAKEN_FORK);
		pthread_mutex_lock(p->left);
		output_log(p->print, p->index, TAKEN_FORK);
	}
}

void	release_forks(t_philo *p)
{
	if (!is_dead(p))
	{
		pthread_mutex_unlock(p->right);
		pthread_mutex_unlock(p->left);
	}
}

// change is_finished in eat_meal()

void	eat_meal(t_philo *p)
{
	if (!is_dead(p))
	{
		update_lastmeal_time(output_log(p->print, p->index, EATING), p);
		my_usleep(p->params[TIME_TO_EAT]);
	}
}

void	sleep_well(t_philo *p)
{
	if (!is_dead(p) && !is_finished(p))
	{
		output_log(p->print, p->index, SLEEPING);
		my_usleep(p->params[TIME_TO_SLEEP]);
	}
}
