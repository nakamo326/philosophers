#include "philosophers.h"

// for error management, its should not be thread?

// need to check manage all output
void	output_log(pthread_mutex_t *print, int p_num, t_log_i log_i)
{
	const char		*log_str[5] = {" has taken a fork",
	" is eating", " is sleeping", " is thinking", " died"};

	pthread_mutex_lock(print);
	printf("%ld %d%s\n", get_time(), p_num, log_str[log_i]);
	pthread_mutex_unlock(print);
	return (NULL);
}
