#include "philosophers_bonus.h"

void	philo_routine(t_philo *philo)
{
	update_lastmeal_time(get_time(), philo);
	if (pthread_create(&philo->doctor, NULL, doctor_routine, philo)
		|| 	pthread_detach(philo->doctor))
		exit(exit_free(philo->info, philo, "failed to create thread"));
	if (philo->info->params[NUM_OF_PHILOS] == 1)
	{
		output_log(philo, TAKEN_FORK);
		exit(exit_free(philo->info, philo, NULL));
	}
	if (philo->index % 2 == 0)
		my_usleep(1);
	while (true)
	{
		shake_forks(philo);
		eat_meal(philo);
		release_forks(philo);
		sleep_well(philo);
		think_about_truth(philo);
	}
	exit(exit_free(philo->info, philo, NULL));
}

void	*doctor_routine(void *philo)
{
	t_philo	*p;
	long	now;
	long	lasttime;

	p = (t_philo *)philo;
	while (true)
	{
		usleep(1000);
		now = get_time();
		lasttime = read_lastmeal_time(p);
		if (now - lasttime >= p->info->params[TIME_TO_DIE])
		{
			sem_wait(p->info->print);
			printf("%ld %d died\n", now, p->index);
			sem_post(p->info->print);
			sem_post(p->info->is_dead);
			exit(EXIT_SUCCESS);
		}
	}
	return (NULL);
}
