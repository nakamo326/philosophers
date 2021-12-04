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
}	t_log_i;

typedef struct s_philo
{
	int				index;
	pthread_t		th;
	int				*params;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	*print;
	pthread_mutex_t	access_to_last_meal;
	long			last_meal_time;
}	t_philo;

typedef struct s_info
{
	int				params[5];
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print;
}	t_info;

int			exit_free(t_info *info, t_philo *philos, char *err);
bool		parse_arg(t_info *info, int argc, char **argv);
bool		start_sims(t_info info, t_philo *philos);

bool		init_info(t_info *info);
t_philo		*init_philos(t_info info);

void		*philo_routine(void *philo);

long		get_time(void);
void		sleep_well(int ms);

// logger
void		output_log(pthread_mutex_t *print, int p_num, t_log_i log_i);

// libft
size_t		ft_strlen(const char *s);
bool		ft_isdigits(char *s);
long long	ft_atoll(const char *nptr);

#endif // PHILOSOPHERS_H
