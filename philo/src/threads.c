/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:08:46 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/14 16:44:35 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	collect_threads(t_table *table, int	index)
{
	while (index > -1)
	{
		if (pthread_join(table->philos[index]->thread, NULL))
			return (ft_exit(ERR_COL_THR, table, ERROR));
		index--;
	}
	return (1);
}

int	start_philo(t_table *table)
{
	int	i;

	i = -1;
	table->start_time = get_time();
	if (table->start_time < 0)
		return (ft_exit(ERR_TIME, table, ERROR));
	while (++i < table->n_phil)
	{
		if (pthread_create(&table->philos[i]->thread, NULL, 
					&philo_routine, NULL))
			return (collect_threads(table, i));
	}
	return (0);
}