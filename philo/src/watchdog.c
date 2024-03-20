/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watchdog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:04:21 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/20 14:39:53 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	check_death(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->n_phil)
	{
		if (get_time() - table->philos[i]->last_meal >= table->tdie
			&& table->finish == 0)
		{
			pthread_mutex_lock(&table->philos[i]->meal_lock);
			table->finish = 1;
			pthread_mutex_unlock(&table->philos[i]->meal_lock);
			print_change(table->philos[i], DIED);
		}
	}
}

void	*watchdog(void *arg)
{
	t_table	*table;

	table = arg;
	while (1)
	{
		check_death(table);
		if (table->finish == 1)
			break ;
	}
	return (NULL);
}
