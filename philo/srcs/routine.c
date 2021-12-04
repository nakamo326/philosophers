#include "philosophers.h"

bool	eat_meal(t_philo *p)
{
	pthread_mutex_lock(p->right);
	pthread_mutex_lock(p->left);
	

	return (true);
}

void	*philo_routine(void *philo)
{
	int		i;
	t_philo	*p;

	p = (t_philo *)philo;
	i = 0;
	while (i < p->params[LIMIT_TIMES_TO_DIE])
	{
		//check is_dead before every action
		if(!eat_meal(p))
			return (p);
		sleep_well(p->params[TIME_TO_SLEEP]);
		// think_about_truth(p);?
	}
	return (p);
}
