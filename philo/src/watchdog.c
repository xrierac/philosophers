/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watchdog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:04:21 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/21 11:51:33 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	check_table(t_table *table)
{
	int	i;
	int	total_meals;

	total_meals = 0;
	i = -1;
	while (++i < table->n_phil)
	{
		pthread_mutex_lock(&table->philos[i]->time_lock);
		if (get_time() - table->philos[i]->last_meal >= table->tdie
			&& get_death_status(table) == 0)
		{
			pthread_mutex_lock(&table->dead_lock);
			table->finish = 1;
			pthread_mutex_unlock(&table->dead_lock);
			print_change(table->philos[i], DIED);
		}
		pthread_mutex_unlock(&table->philos[i]->time_lock);
		pthread_mutex_lock(&table->philos[i]->meal_lock);
		total_meals += table->philos[i]->n_meals;
		pthread_mutex_unlock(&table->philos[i]->meal_lock);
	}
	if (table->must_eat > 0 && total_meals >= table->must_eat * table->n_phil)
		return (1);
	return (0);
}

void	*watchdog(void *arg)
{
	t_table	*table;

	table = arg;
	while (1)
	{
		if (check_table(table) == 1)
			break ;
		if (get_death_status(table))
			break ;
	}
	return (NULL);
}
