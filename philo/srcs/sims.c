#include "philosophers.h"

bool	start_sims(t_philo *philos)
{
	t_philo	*p;

	for (int i = 0; i < philos->info->params[NUM_OF_PHILOS]; i++)
	{
		p = &(philos[i]);
		if (pthread_create(&p->th, NULL, philo_routine, p)
			|| pthread_create(&p->doctor, NULL, doctor_routine, p))
			return (false);
	}
	return (true);
}

bool	join_philos(t_philo *philos)
{
	for (int i = 0; i < philos->info->params[NUM_OF_PHILOS]; i++)
	{
		if (pthread_join(philos[i].th, NULL)
			|| pthread_join(philos[i].doctor, NULL))
			return (false);
	}
	return (true);
}
