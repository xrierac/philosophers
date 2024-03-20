/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:56:03 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/20 11:40:48 by xriera-c         ###   ########.fr       */
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

int	parse_input(char *argv[], int argc, t_table *table)
{
	table->n_phil = get_parse(argv[1]);
	table->tdie = get_parse(argv[2]);
	table->teat = get_parse(argv[3]);
	table->tsleep = get_parse(argv[4]);
	table->must_eat = -1;
	if (argc == 6)
		table->must_eat = get_parse(argv[5]);
	if (table->n_phil <= 0 || table->tdie < 0 || table->teat < 0
		|| table->tsleep < 0 || table->must_eat < -1)
		return (-1);
	return (0);
}
