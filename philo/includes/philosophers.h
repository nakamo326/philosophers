#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

# include <stdbool.h>
# include <limits.h>
# include <errno.h>

typedef enum e_arg_index
{
	num_of_philos,
	time_to_die,
	time_to_eat,
	time_to_sleep,
	limit_times_to_die,
}	t_arg_index;

typedef struct s_log {
	pthread_mutex_t	*print;
	int				p_num;
	int				log_num;
}	t_log;

typedef struct s_philo
{
	pthread_mutex_t	*left; // lefthand side fork
	pthread_mutex_t	*right; // righthand side fork
	pthread_mutex_t	*print; // permission to output log
	long			time_last_eating;
}	t_philo;

typedef struct s_info
{
	int		params[5];
	t_philo	*p_arr;
}	t_info;

int			return_error(char *msg);
bool		parse_arg(t_info *info, int argc, char **argv);
void		start_sims(t_info info);

// logger
void		output_log(pthread_mutex_t *print, int p_num, int log_num);
void		*output_thread(void *log);

// libft
size_t		ft_strlen(const char *s);
bool		ft_isdigits(char *s);
long long	ft_atoll(const char *nptr);

#endif // PHILOSOPHERS_H
