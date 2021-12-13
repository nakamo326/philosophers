#include "philosophers.h"

int	exit_free(t_info *info, t_philo *philos, char *err)
{
	if (info != NULL)
	{
		free(info->forks);
	}
	free(philos);
	if (err != NULL)
	{
		printf("%s\n", err);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

bool	init_info(t_info *info)
{
	int	i;
	int	ret;

	info->forks = malloc(sizeof(pthread_mutex_t) * info->params[NUM_OF_PHILOS]);
	if (info->forks == NULL)
		return (false);
	i = 0;
	while (i < info->params[NUM_OF_PHILOS])
	{
		ret = pthread_mutex_init(&info->forks[i], NULL);
		if (ret != 0)
			return (false);
		i++;
	}
	if (pthread_mutex_init(&info->print, NULL))
		return (false);
	pthread_mutex_lock(&info->print);
	info->is_dead = false;
	info->fullfill_num = 0;
	pthread_mutex_unlock(&info->print);
	return (true);
}

t_philo	*init_philos(t_info *info)
{
	int		i;
	int		num;
	t_philo	*philos;

	num = info->params[NUM_OF_PHILOS];
	philos = malloc(sizeof(t_philo) * num);
	i = 0;
	while (philos != NULL && i < num)
	{
		philos[i].info = info;
		philos[i].index = i + 1;
		philos[i].left = &info->forks[i];
		philos[i].right = &info->forks[(i + num - 1) % num];
		pthread_mutex_init(&philos[i].access_to_last_meal, NULL);
		philos[i].times_of_finished_meal = 0;
		i++;
	}
	return (philos);
}
