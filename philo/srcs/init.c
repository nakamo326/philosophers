#include "philosophers.h"



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
	info->print = malloc(sizeof(pthread_mutex_t));
	if (info->print == NULL)
		return (false);
	ret = pthread_mutex_init(info->print, NULL);
	if (ret != 0)
		return (false);
	return (true);
}

bool	init_philos(t_philo *philos, t_info info)
{
	int	i;
	int	num;

	num = info.params[NUM_OF_PHILOS];
	philos = malloc(sizeof(t_philo) * num);
	if (philos == NULL)
		return (false);
	i = 0;
	while (i < num)
	{
		philos[i].index = i + 1;
		philos[i].params = info.params;
		philos[i].left = &info.forks[i];
		philos[i].right = &info.forks[(i + num - 1) % num];
		philos[i].print = info.print;
		pthread_mutex_init(&philos[i].access_to_last_meal, NULL);
		philos[i].last_meal_time = get_time();
		i++;
	}
	return (true);
}
