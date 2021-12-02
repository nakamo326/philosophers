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

typedef enum e_arg_index
{
	num_of_philos,
	time_to_die,
	time_to_eat,
	time_to_sleep,
	limit_times_to_die,
}	t_arg_index;

typedef struct s_philo
{
	int	params[5];
}	t_philo;

int			return_error(char *msg);
bool		parse_arg(t_philo *p, int argc, char **argv);
void		start_sims(t_philo p);

size_t		ft_strlen(const char *s);
void		ft_putstr_fd(char *s, int fd);
bool		ft_isdigits(char *s);
long long	ft_atoll(const char *nptr);

#endif // PHILOSOPHERS_H