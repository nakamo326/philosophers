#include "philosophers.h"

typedef struct s_log {
	int p_num;
	int log_num;
}	t_log;

void *output_log(void* log){
	const char *log_str[5] = {" has taken a fork",
	" is eating", " is sleeping", " is thinking", " died" };
	t_log *l;
	struct timeval tv;

	// need to lock mutex and unlock
	gettimeofday(&tv, NULL);
	l = (t_log *)log;
	printf("%ld %d%s\n", tv.tv_sec, l->p_num, log_str[l->log_num]);
	return NULL;
}

void start_sims(t_info info) {
	(void)info;
	pthread_t test;
	t_log testlog;
	testlog.p_num = 1;
	testlog.log_num = 2;
	pthread_create(&test, NULL, output_log, &testlog);
	pthread_join(test, NULL);
}