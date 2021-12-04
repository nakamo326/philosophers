#include "philosophers.h"

void	*philo_routine(void *philo)
{
	t_philo *p;

	p = (t_philo *)philo;

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
