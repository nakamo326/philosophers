#include "philosophers.h"

bool	init_info(t_info info) {
	int i;
	int ret;

	info.forks = malloc(sizeof(pthread_mutex_t) * info.params[NUM_OF_PHILOS]);
	if (info.forks == NULL)
		return (false);
	// move init mutex to out of func
	i = 0;
	while (i < info.params[NUM_OF_PHILOS])
	{
		ret = pthread_mutex_init(&info.forks[i], NULL);
		if (ret != 0)
			return (false);
		i++;
	}
	info.print = malloc(sizeof(pthread_mutex_t));
	if (info.print == NULL)
		return (false);
	info.p_arr = malloc(sizeof(t_philo) * info.params[NUM_OF_PHILOS]);
	if (info.p_arr == NULL)
		return (false);
	return (true);
}

bool	init_philos(t_info info) {
	int i;
	int num;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	i = 0;
	num = info.params[NUM_OF_PHILOS];
	while (i < num)
	{
		info.p_arr[i].params = info.params;
		info.p_arr[i].left = &info.forks[i];
		info.p_arr[i].right = &info.forks[(i + num - 1) % num];
		info.p_arr[i].print = info.print;
		info.p_arr[i].time_last_eating = tv.tv_sec;
		i++;
	}
	return (true);
}

int	start_sims(t_info info)
{
	if (!init_info(info))
		return (print_error("failed to init infos.\n"));
	init_philos(info);
}
