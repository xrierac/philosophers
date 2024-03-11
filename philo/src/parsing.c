/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:56:03 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/11 12:31:53 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static long	get_parse(char *str)
{
	long	nbr;

	if (ft_strlen(str) > 11 || str[0] == '\0')
		return (-2);
	nbr = ft_atol(str);
	if (nbr > INT_MAX || nbr < 0)
		return (-2);
	return (nbr);
}

int	parse_input(char *argv[], int argc, t_sim *sim)
{
	sim->n_phil = get_parse(argv[1]);
	sim->tdie = get_parse(argv[2]);
	sim->teat = get_parse(argv[3]);
	sim->tsleep = get_parse(argv[4]);
	sim->n_eat = -1;
	if (argc == 6)
		sim->n_eat = get_parse(argv[5]);
	if (sim->n_phil <= 0 || sim->tdie < 0 || sim->teat < 0 || 
			sim->tsleep < 0 || sim->n_eat < -1)
		return (-1);
	return (0);
}
