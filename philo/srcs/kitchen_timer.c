#include "philosophers.h"

long	get_time(void)
{
	struct timeval	tp;
	long			ms;

	gettimeofday(&tp, NULL);
	ms = tp.tv_sec * 1000;
	ms += tp.tv_usec / 1000;
	return (ms);
}

void	my_usleep(int ms)
{
	long	start;

	//check is dead
	start = get_time();
	while (get_time() - start < ms)
	{
		usleep(1000);
	}
}
