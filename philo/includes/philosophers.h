#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

# include <stdbool.h>
# include <limits.h>
# include <errno.h>

# define TAKEN_FORK " has taken a fork"
# define EATING " is eating"
# define SLEEPING " is sleeping"
# define THINKING " is thinking"

typedef enum e_arg_index
{
	NUM_OF_PHILOS,
	TIME_TO_DIE,
	TIME_TO_EAT,
	TIME_TO_SLEEP,
	LIMIT_TIMES_TO_DIE,
}	t_arg_index;

typedef struct s_info
{
	int				params[5];
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	bool			is_dead;
	int				fullfill_num;
	bool			is_odd;
}	t_info;

typedef struct s_philo
{
	t_info			*info;
	int				index;
	pthread_t		th;
	pthread_t		doctor;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	*print;
	pthread_mutex_t	access_to_last_meal;
	long			last_meal_time;
	long			times_of_finished_meal;
}	t_philo;

// init
bool	init_info(t_info *info);
t_philo	*init_philos(t_info *info);
int		exit_free(t_info *info, t_philo *philos, char *err);

// sims
bool	start_sims(t_philo *philos);
bool	join_philos(t_philo *philos);

// routine
void	*philo_routine(void *philo);
void	*doctor_routine(void *philo);

// actions
void	shake_forks(t_philo *p);
void	eat_meal(t_philo *p);
void	release_forks(t_philo *p);
void	sleep_well(t_philo *p);
void	think_about_truth(t_philo *p);

// utils
long	get_time(void);
void	my_usleep(int ms);
long	output_log(t_philo *p, const char *str);
bool	is_dead(t_philo *p);
bool	is_fullfilled(t_philo *p);
void	update_lastmeal_time(long time, t_philo *p);
long	read_lastmeal_time(t_philo *p);

// parse
bool	parse_arg(t_info *info, int argc, char **argv);
size_t	ft_strlen(const char *s);
bool	ft_isdigits(char *s);
int		ft_atoi(const char *nptr);

#endif // PHILOSOPHERS_H
