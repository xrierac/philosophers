/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:57:19 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/12 11:54:51 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

t_sim	*init_sim(int argc, char *argv[])
{
	t_sim	*sim;

	sim = malloc(sizeof(t_sim));
	if (!sim)
		exit_error("Memory allocation failed\n", sim);
	if (parse_input(argv, argc, sim) < 0)
		exit_error("Wrong argument\n", sim);
	sim->phteam = init_team(sim);
	return (sim);
}

t_philo **init_team(t_sim *sim)
{
	t_philo	**phteam;
	t_philo	*philo;
	int		i;

	phteam = malloc(sizeof(t_philo) * sim->n_phil);
	if (!phteam)
		exit_error("Memory allocation failed\n", sim);
	i = -1;
	while (++i < sim->n_phil)
	{
		philo = malloc(sizeof(t_philo));
		if (!philo)
			exit_error("Memory allocation failed\n", sim);
		phteam[i] = philo;
		pthread_mutex_init(&phteam[i]->meal_lock, NULL);
		phteam[i]->id = i + 1;
	}
	return (phteam);
}
/*
t_philo	*init_philo(t_sim *sim)
{
	int	i;

	i = -1;
	while (++i < sim->n_phil)
	{
		if (pthread_create(&sim->phteam[i]->thread, NULL, FUNCTION, NULL) != 0)
			exit_error("Problem creating new thread\n", sim);
	}
}
*/
