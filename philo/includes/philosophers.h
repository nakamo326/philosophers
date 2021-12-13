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

typedef struct s_info
{
	int				params[5];
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	access_to_is_dead;
	bool			is_dead;
	pthread_mutex_t	access_to_fullfill;
	int				fullfill_num;
}	t_info;

typedef struct s_philo
{
	t_info			*info;
	int				index;
	pthread_t		th;
	pthread_t		doctor;
	int				*params;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	*print;
	pthread_mutex_t	access_to_last_meal;
	long			last_meal_time;
	long			times_of_finished_meal;
}	t_philo;

int			exit_free(t_info *info, t_philo *philos, char *err);
bool		start_sims(t_info info, t_philo *philos);
void		join_philos(t_info info, t_philo *philos);

bool		init_info(t_info *info);
t_philo		*init_philos(t_info *info);

void		*philo_routine(void *philo);
void		shake_forks(t_philo *p);
void		eat_meal(t_philo *p);
void		release_forks(t_philo *p);
void		sleep_well(t_philo *p);
void		think_about_truth(t_philo *p);

void		*doctor_routine(void *philo);

long		get_time(void);
void		my_usleep(int ms);
long		output_log(t_philo *p, t_log_i log_i);
bool		is_dead(t_philo *p);
bool		is_fullfilled(t_philo *p);
void		update_lastmeal_time(long time, t_philo *p);
long		read_lastmeal_time(t_philo *p);

// parse
bool		parse_arg(t_info *info, int argc, char **argv);
size_t		ft_strlen(const char *s);
bool		ft_isdigits(char *s);
long long	ft_atoll(const char *nptr);

#endif // PHILOSOPHERS_H
