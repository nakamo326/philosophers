#include "philosophers.h"

	// pthread_join(test, NULL);
	// need to check manage all output
void	output_log(pthread_mutex_t *print, int p_num, int log_num)
{
	pthread_t	th;
	t_log		log;

	log.print = print;
	log.p_num = p_num;
	log.log_num = log_num;
	pthread_create(&th, NULL, output_thread, &log);
	pthread_detach(th);
}

void	*output_thread(void *log)
{
	const char		*log_str[5] = {" has taken a fork",
	" is eating", " is sleeping", " is thinking", " died" };
	t_log			*l;
	struct timeval	tv;

	l = (t_log *)log;
	gettimeofday(&tv, NULL);
	pthread_mutex_lock(l->print);
	printf("%ld %d%s\n", tv.tv_sec, l->p_num, log_str[l->log_num]);
	pthread_mutex_unlock(l->print);
	return (NULL);
}
