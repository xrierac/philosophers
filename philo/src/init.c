/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:57:19 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/15 15:31:16 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	init_table(int argc, char *argv[], t_table *table)
{
	table->philos = NULL;
	table->forks_lock = NULL;
	table->finish = 0;
	if (parse_input(argv, argc, table) < 0)
		return (ft_exit(ERR_ARG, table, ERROR));
	if (sit_philos(table) < 0)
		return (ft_exit(ERR_MALLOC, table, ERROR));
	if (init_forks(table) != 0)
		return (ft_exit(ERR_MUTEX_I, table, ERROR));
	return (0);
}

int	sit_philos(t_table *table)
{
	int		i;

	table->philos = malloc(sizeof(t_philo *) * table->n_phil);
	if (!table->philos)
		return (-1);
	i = -1;
	while (++i < table->n_phil)
	{
		table->philos[i] = malloc(sizeof(t_philo));
		if (!table->philos[i])
			return (-1);
	}
	init_philos(table);
	return (0);
}

void	init_philos(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->n_phil)
	{
		table->philos[i]->id = i + 1;
		table->philos[i]->n_meals = 0;
		table->philos[i]->forks[0] = i;
		table->philos[i]->forks[1] = i + 1;
		if (i == table->n_phil - 1)
			table->philos[i]->forks[1] = 0;
		table->philos[i]->table = table;
	}
}

int	init_forks(t_table *table)
{
	int	i;

	i = -1;
	table->forks_lock = malloc(sizeof(pthread_mutex_t) * table->n_phil);
	if (!table->forks_lock)
		return (-1);
	while (++i < table->n_phil)
	{
		if (pthread_mutex_init(&table->forks_lock[i], NULL))
			return (destroy_forks(table, i));
	}
	return (0);
}
