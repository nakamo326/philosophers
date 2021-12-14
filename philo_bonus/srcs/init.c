#include "philosophers_bonus.h"

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

	info->forks = sem_open("forks", O_CREAT, O_RDWR,info->params[NUM_OF_PHILOS]);
	if (info->forks == SEM_FAILED)
		return (false);
	i = 0;
	info->print = sem_open("print", O_CREAT, O_RDWR,info->params[NUM_OF_PHILOS]);
	if (info->print == SEM_FAILED)
		return (false);
	info->is_dead = false;
	info->fullfill_num = 0;
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
		philos[i].times_of_finished_meal = 0;
		i++;
	}
	return (philos);
}
