#include "philosophers.h"

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

bool	start_sims(t_info info)
{
	int		i;
	t_philo	*p;

	i = 0;
	while (i < info.params[NUM_OF_PHILOS])
	{
		p = &(info.p_arr[i]);
		if (pthread_create(&p->th, NULL, philo_routine, p) != 0)
			return (false);
		i++;
	}

	// move another func
	for (size_t i = 0; i < 4; i++)
	{
		pthread_join(info.p_arr[i].th, NULL);
	}
	
	return (true);
}
