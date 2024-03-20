/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:14:48 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/20 16:53:04 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	destroy_mutexes(t_table *table, int index)
{
	int	i;

	i = 0;
	i += destroy_forks(table, index);
	i += destroy_meals(table, index);
	i += destroy_time(table, index);
	if (pthread_mutex_destroy(&table->dead_lock))
		i++;
	return (i);
}

int	destroy_forks(t_table *table, int index)
{
	int	i;

	i = 0;
	while (index > -1)
	{
		if (pthread_mutex_destroy(&table->forks_lock[index]))
			i++;
		index--;
	}
	return (i);
}

int	destroy_meals(t_table *table, int index)
{
	while (index > -1)
	{
		if (pthread_mutex_init(&table->philos[index]->meal_lock))
			return (1);
		index--;
	}
	return (0);
}

int	destroy_time(t_table *table, int index)
{
	while (index > -1)
	{
		if (pthread_mutex_init(&table->philos[index]->time_lock))
			return (1);
		index--;
	}
	return (0);
}

int	init_mutexes(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->n_phil)
	{
		if (pthread_mutex_init(&table->philos[i]->meal_lock, NULL))
			return (destroy_meals(table, i - 1), 1);
	}
	i = -1;
	while (++i < table->n_phil)
	{
		if (pthread_mutex_init(&table->philos[i]->time_lock, NULL))
		{
			destroy_meals(table, table->n_phil - 1);
			return (destroy_time(table, i - 1), 1);
		}
	}
	if (pthread_mutex_init(&table->dead_lock, NULL))
		return (1);
	return (0);
}
