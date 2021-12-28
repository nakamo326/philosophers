#include "philosophers.h"

int	exit_free(t_info *info, t_philo *philos, char *err)
{
	if (info != NULL) {
		free(info->forks);
	}
	free(philos);
	if (err != NULL) {
		printf("%s\n", err);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

bool	init_info(t_info *info)
{
	info->forks = malloc(sizeof(pthread_mutex_t) * info->params[NUM_OF_PHILOS]);
	if (info->forks == NULL)
		return (false);
	for (int i = 0; i < info->params[NUM_OF_PHILOS]; i++) {
		if (pthread_mutex_init(&info->forks[i], NULL))
			return (false);
	}
	if (pthread_mutex_init(&info->print, NULL)) {
		return (false);
	}
	if (info->params[NUM_OF_PHILOS] % 2 == 1) {
		info->is_odd = true;
	}
	return (true);
}

t_philo	*init_philos(t_info *info)
{
	int		num;
	t_philo	*philos;

	num = info->params[NUM_OF_PHILOS];
	philos = malloc(sizeof(t_philo) * num);
	if (philos == NULL) {
		return (NULL);
	}
	for (int i = 0; i < num; i++) {
		philos[i].info = info;
		philos[i].index = i + 1;
		philos[i].left = &info->forks[i];
		philos[i].right = &info->forks[(i + num - 1) % num];
		pthread_mutex_init(&philos[i].access_to_last_meal, NULL);
		philos[i].times_of_finished_meal = 0;
	}
	return (philos);
}
