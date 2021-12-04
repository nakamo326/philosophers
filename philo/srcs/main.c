#include "philosophers.h"

int	print_error(char *msg)
{
	printf("%s\n", msg);
	return (EXIT_FAILURE);
}

bool	parse_arg(t_info *info, int argc, char **argv)
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
		info->params[i - 1] = tmp;
		i++;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_info	info;

	init_info(&info);
	if (!parse_arg(&info, argc, argv))
		return (print_error("Invalid arguments."));
	if (!make_info(&info))
	{
		print_error("failed to init infos.");
		return (free_info(info, EXIT_FAILURE));
	}
	init_philos(info);
	start_sims(info);
	
	return (free_info(info, EXIT_SUCCESS));
}
