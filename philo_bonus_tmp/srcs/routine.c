#include "philosophers_bonus.h"

void	philo_routine(t_philo *philo)
{
	update_lastmeal_time(get_time(), philo);
	if (pthread_create(&philo->doctor, NULL, doctor_routine, philo))
	//	|| 	pthread_detach(philo->doctor))
		exit(exit_free(philo->info, philo, "failed to create thread"));
	if (philo->info->params[NUM_OF_PHILOS] == 1)
	{
		output_log(philo, TAKEN_FORK);
		exit(exit_free(philo->info, philo, NULL));
	}
	if (philo->index % 2 == 0)
		my_usleep(1);
	while (true) // want to break if dead or fullfilled
	{
		shake_forks(philo);
		eat_meal(philo);
		release_forks(philo);
		sleep_well(philo);
		think_about_truth(philo);
	}
	exit(exit_free(philo->info, philo, NULL));
}
