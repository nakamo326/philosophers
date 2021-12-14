#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <pthread.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <signal.h>

# include <stdbool.h>
# include <limits.h>
# include <errno.h>

# define TAKEN_FORK " has taken a fork"
# define EATING " is eating"
# define SLEEPING " is sleeping"
# define THINKING " is thinking"

# define SEM_FORK "sem_fork"
# define SEM_PRINT "sem_print"
# define SEM_TICKET "sem_ticket"

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
	int		params[5];
	pid_t	*procs;
	sem_t	*forks;
	sem_t	*print;
	sem_t	*ticket;
	bool	is_dead;
}	t_info;

typedef struct s_philo
{
	t_info		*info;
	int			index;
	pthread_t	doctor;
	long		last_meal_time;
	long		times_of_finished_meal;
}	t_philo;

int			exit_free(t_info *info, t_philo *philo, char *err);
bool		start_sims(t_philo *philo);
void		count_ticket(t_info *info);
void		join_philos(t_info *info);
void		unlink_all_sem();

bool		init_info(t_info *info);
t_philo		*init_philo(t_info *info);

void		philo_routine(t_philo *philo);
void		shake_forks(t_philo *p);
void		eat_meal(t_philo *p);
void		release_forks(t_philo *p);
void		sleep_well(t_philo *p);
void		think_about_truth(t_philo *p);

void		*doctor_routine(void *philo);

long		get_time(void);
void		my_usleep(int ms);
long		output_log(t_philo *p, const char *str);
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
