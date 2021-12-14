#include "philosophers_bonus.h"

void	philo_routine(t_philo *philo)
{
	update_lastmeal_time(get_time(), philo);
	pthread_create(&philo->doctor, NULL, doctor_routine, philo);
	if (philo->info->params[NUM_OF_PHILOS] == 1)
	{
		output_log(philo, TAKEN_FORK);
		pthread_join(philo->doctor, NULL);
		exit(exit_free(philo->info, philo, NULL));
	}
	if (philo->index % 2 == 0)
		my_usleep(1);
	while (!is_dead(philo) && !is_fullfilled(philo))
	{
		shake_forks(philo);
		eat_meal(philo);
		release_forks(philo);
		sleep_well(philo);
		think_about_truth(philo);
	}
	pthread_join(philo->doctor, NULL);
	exit(exit_free(philo->info, philo, NULL));
}

void	*doctor_routine(void *philo)
{
	t_philo	*p;
	long	now;
	long	lasttime;

	p = (t_philo *)philo;
	while (!is_dead(p) && !is_fullfilled(p))
	{
		usleep(1000);
		sem_wait(p->info->print);
		now = get_time();
		lasttime = read_lastmeal_time(p);
		if (now - lasttime >= p->info->params[TIME_TO_DIE]
			&& p->info->is_dead == false)
		{
			printf("%ld %d died\n", now, p->index);
			p->info->is_dead = true;
		}
		sem_post(p->info->print);
	}
	return (NULL);
}
