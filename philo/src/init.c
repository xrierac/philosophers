/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:57:19 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/13 11:13:39 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

t_table	*init_table(int argc, char *argv[])
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		exit_error(ERR_MALLOC, table);
	if (parse_input(argv, argc, table) < 0)
		exit_error(ERR_ARG, table);
	table->philos = sit_philos(table);
	return (table);
}

t_philo **sit_philos(t_table *table)
{
	t_philo	**philos;
	t_philo	*philo;
	int		i;

	philos = malloc(sizeof(t_philo) * table->n_phil);
	if (!philos)
		exit_error(ERR_MALLOC, table);
	i = -1;
	while (++i < table->n_phil)
	{
		philo = malloc(sizeof(t_philo));
		if (!philo)
			exit_error(ERR_MALLOC, table);
		philos[i] = philo;
	}
	init_philos(table);
	return (philos);
}

void	init_philos(t_table *table)
{
	int	i;

	i = 0;
	while (table->philos[i])
	{
		table->philos[i]->id = i + 1;
		table->philos[i]->n_meals = 0;
		table->philos[i]->forks[0] = i;
		table->philos[i]->forks[1] = i + 1;
		if (i == 0)
			table->philos[i]->forks[0] = table->n_phil;
		if (i == table->n_phil - 1)
			table->philos[i]->forks[1] = 1;
		i++;
	}
}
