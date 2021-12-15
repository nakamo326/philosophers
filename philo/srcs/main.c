/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 21:45:21 by ynakamot          #+#    #+#             */
/*   Updated: 2021/12/15 21:45:22 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philos;

	if (!parse_arg(&info, argc, argv))
		return (exit_free(NULL, NULL, "Invalid arguments."));
	if (!init_info(&info))
		return (exit_free(&info, NULL, "failed to init infos."));
	philos = init_philos(&info);
	if (philos == NULL)
		return (exit_free(&info, philos, "failed to init philos."));
	start_sims(philos);
	join_philos(philos);
	return (exit_free(&info, philos, NULL));
}
