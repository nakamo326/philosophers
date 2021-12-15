#include "philosophers.h"

bool	start_sims(t_philo *philos)
{
	int		i;
	t_philo	*p;

	i = 0;
	while (i < philos->info->params[NUM_OF_PHILOS])
	{
		p = &(philos[i]);
		if (pthread_create(&p->th, NULL, philo_routine, p)
			|| pthread_create(&p->doctor, NULL, doctor_routine, p))
			return (false);
		i++;
	}
	return (true);
}

bool	join_philos(t_philo *philos)
{
	int	i;
	int	num;

	i = 0;
	num = philos->info->params[NUM_OF_PHILOS];
	while (i < num)
	{
		if (pthread_join(philos[i].th, NULL) || pthread_join(philos[i].doctor, NULL))
			return (false);
		i++;
	}
	return (true);
}
