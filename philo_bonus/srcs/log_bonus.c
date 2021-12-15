/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 21:46:04 by ynakamot          #+#    #+#             */
/*   Updated: 2021/12/15 21:46:04 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

long	output_log(t_philo *p, const char *str)
{
	long	time;

	time = get_time();
	sem_wait(p->info->print);
	printf("%ld %d%s\n", time, p->index, str);
	sem_post(p->info->print);
	return (time);
}
