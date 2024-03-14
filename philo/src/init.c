/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:57:19 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/14 11:12:16 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	init_table(int argc, char *argv[], t_table *table)
{
	table = malloc(sizeof(t_table));
	if (!table)
		return (ft_exit(ERR_MALLOC, NULL, ERROR));
	table->philos = NULL;
	if (parse_input(argv, argc, table) < 0)
		return (ft_exit(ERR_ARG, table, ERROR));
	return (sit_philos(table));
}

int	sit_philos(t_table *table)
{
	int		i;

	table->philos = malloc(sizeof(t_philo *) * table->n_phil);
	if (!table->philos)
		return (ft_exit(ERR_MALLOC, table, ERROR));
	i = -1;
	while (++i < table->n_phil)
	{
		table->philos[i] = malloc(sizeof(t_philo));
		if (!table->philos[i])
			return (ft_exit(ERR_MALLOC, table, ERROR));
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
		if (i == 0)
			table->philos[i]->forks[0] = table->n_phil;
		if (i == table->n_phil - 1)
			table->philos[i]->forks[1] = 1;
	}
}
