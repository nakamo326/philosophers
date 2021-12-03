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
	NUM_OF_PHILOS,
	TIME_TO_DIE,
	TIME_TO_EAT,
	TIME_TO_SLEEP,
	LIMIT_TIMES_TO_DIE,
}	t_arg_index;

typedef enum e_log_i
{
	TAKEN_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED,
} t_log_i;

typedef struct s_log {
	pthread_mutex_t	*print;
	int				p_num;
	t_log_i			log_i;
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
void		output_log(pthread_mutex_t *print, int p_num, t_log_i log_i);
void		*output_thread(void *log);

// libft
size_t		ft_strlen(const char *s);
bool		ft_isdigits(char *s);
long long	ft_atoll(const char *nptr);

#endif // PHILOSOPHERS_H
