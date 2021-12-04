#include "philosophers.h"

void	init_info(t_info *info)
{
	(void)info;
	info->p_arr = NULL;
	info->forks = NULL;
	info->print = NULL;
}

int	free_info(t_info info, int ret)
{
	free(info.p_arr);
	free(info.forks);
	free(info.print);
	return (ret);
}

bool	make_info(t_info *info)
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
	info->p_arr = malloc(sizeof(t_philo) * info->params[NUM_OF_PHILOS]);
	if (info->p_arr == NULL)
		return (false);
	return (true);
}

bool	init_philos(t_info *info)
{
	int				i;
	int				num;

	i = 0;
	num = info->params[NUM_OF_PHILOS];
	while (i < num)
	{
		info->p_arr[i].index = i + 1;
		info->p_arr[i].params = info->params;
		info->p_arr[i].left = &info->forks[i];
		info->p_arr[i].right = &info->forks[(i + num - 1) % num];
		info->p_arr[i].print = info->print;
		info->p_arr[i].time_last_eating = get_time();
		i++;
	}
	return (true);
}
