#include "philosophers.h"

void	shake_forks(t_philo *p)
{
	if (!is_dead(p))
	{
		pthread_mutex_lock(p->right);
		pthread_mutex_lock(p->left);
		output_log(p->print, p->index, TAKEN_FORK);
	}
}

// change is_finished in eat_meal()

