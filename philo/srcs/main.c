#include "philosophers.h"

int	return_error(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	return (EXIT_FAILURE);
}

bool	parse_arg(t_philo *p, int argc, char **argv)
{
	int			i;
	long long	tmp;

	if (!(argc == 5 || argc == 6))
		return (false);
	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 10 || !ft_isdigits(argv[i]))
			return (false);
		tmp = ft_atoll(argv[i]);
		if (tmp <= 0 || tmp > INT_MAX)
			return (false);
		p->params[i] = tmp;
		i++;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_philo	p;

	if (!parse_arg(&p, argc, argv))
		return (return_error("Invalid arguments.\n"));
	start_sims(p);
	return (EXIT_SUCCESS);
}
