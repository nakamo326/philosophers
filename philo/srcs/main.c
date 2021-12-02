#include "philosophers.h"

int	g_test = 9;

int	return_error(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_philo	p;

	if (!parse_arg(&p, argc, argv))
		return (return_error("Invalid arguments.\n"));
	return (EXIT_SUCCESS);
}
