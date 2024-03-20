/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:14:48 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/20 15:29:33 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	destroy_forks(t_table *table, int index)
{
	int	i;

	i = 1;
	while (index > -1)
	{
		if (pthread_mutex_destroy(&table->forks_lock[index]))
			i++;
		index--;
	}
	return (i);
}

int	init_mutexes(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_phil)
	{
		if (pthread_mutex_init(&table->philos[i]->meal_lock, NULL))
			return (destroy_mutexes(table, i - 1, 1));
		i++;
	}
	if (pthread_mutex_init(&table->time_lock, NULL)
		  || pthread_mutex_init(&table->dead_lock, NULL))
		  return (destroy_mutexes(table, i - 1, 0));
	return (0);
}

int	destroy_mutexes(t_table *table, int index, int flag)
{
	while (index > -1)
	{
		if (pthread_mutex_destroy(&table->philos[index]->meal_lock))
			return (-2);
		index--;
	}
	if (flag == 0 && (pthread_mutex_destroy(&table->time_lock)
			|| pthread_mutex_destroy(&table->dead_lock)))
			return (-2);
	return (1);
}
