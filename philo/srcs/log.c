/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 21:45:16 by ynakamot          #+#    #+#             */
/*   Updated: 2021/12/15 21:45:17 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	output_log(t_philo *p, const char *str)
{
	long			time;

	time = get_time();
	pthread_mutex_lock(&p->info->print);
	if (!p->info->is_dead
		&& !(p->info->fullfill_num == p->info->params[NUM_OF_PHILOS]))
	{
		printf("%ld %d%s\n", time, p->index, str);
	}
	pthread_mutex_unlock(&p->info->print);
	return (time);
}
