#include "philosophers.h"

bool	start_sims(t_info info, t_philo *philos)
{
	int		i;
	t_philo	*p;

	i = 0;
	while (i < info.params[NUM_OF_PHILOS])
	{
		p = &(philos[i]);
		if (pthread_create(&p->th, NULL, philo_routine, p) != 0)
			return (false);
		i++;
	}

	// move another func
	for (size_t i = 0; i < 4; i++)
	{
		pthread_join(philos[i].th, NULL);
	}
	
	return (true);
}
