/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:14:48 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/14 15:55:10 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	init_mutexes(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_phil)
	{
		if (pthread_mutex_init(&table->philos[i]->meal_lock, NULL))
				return (destroy_mutexes(table, i));
		i++;
	}
	return (0);
}

int	destroy_mutexes(t_table *table, int index)
{
	while (index > -1)
	{
		if (pthread_mutex_destroy(&table->philos[index]->meal_lock))
			return (-2);
		index--;
	}
	return (1);
}
