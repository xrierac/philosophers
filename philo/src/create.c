/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:58:56 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/11 12:07:26 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_table	*create_table(void)
{
	t_table *table;

	table = malloc(sizeof(t_table));
	return (table);
}

t_philo	*create_philo(void)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	return (philo);
}

t_philo **create_phteam(t_table *table)
{
	t_philo **phteam;

	phteam = malloc(sizeof(t_philo) * table->n_phil);
	return (phteam);
}	
