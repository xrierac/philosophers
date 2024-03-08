/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:56:03 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/08 12:51:12 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

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
	table->nbrphilo = (int)get_parse(argv[2]);
	table->tdie = get_parse(argv[3]);
	table->teat = get_parse(argv[4]);
	table->tsleep = get_parse(argv[5]);
	if (argc == 5)
		table->nbreat = -1;
	else
		table->nbreat = get_parse(argv[6]);
	if (table->nbrphilo < 0 || table->tdie < 0 || table->teat < 0 || 
			table->tsleep < 0 || table->nbreat < -1)
		return (-1);
	return (0);
}
