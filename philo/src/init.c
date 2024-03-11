/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:57:19 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/11 12:32:26 by xriera-c         ###   ########.fr       */
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
	return (sim);
}
