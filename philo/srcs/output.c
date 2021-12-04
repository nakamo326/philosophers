#include "philosophers.h"

// for error management, its should not be thread?

// need to check manage all output
void	output_log(pthread_mutex_t *print, int p_num, t_log_i log_i)
{
	pthread_t	th;
	t_log		log;

	log.print = print;
	log.p_num = p_num;
	log.log_i = log_i;
	pthread_create(&th, NULL, output_thread, &log);
	pthread_detach(th);
}

void	*output_thread(void *log)
{
	const char		*log_str[5] = {" has taken a fork",
	" is eating", " is sleeping", " is thinking", " died" };
	t_log			*l;
	long			time;

	l = (t_log *)log;
	time = get_time();
	pthread_mutex_lock(l->print);
	printf("%ld %d%s\n", time, l->p_num, log_str[l->log_i]);
	pthread_mutex_unlock(l->print);
	return (NULL);
}
