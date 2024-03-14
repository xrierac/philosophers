/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:53:00 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/14 12:35:36 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_exit(char *s, t_table *table, t_status status)
{
	int	i;

	i = -1;
	if (status == ERROR)
		ft_putstr_fd(s, 2);
	if (status == SUCCESS)
		ft_putstr_fd("Success\n", 1);
	if (table && table->philos)
	{
		while (++i < table->n_phil)
			free(table->philos[i]);
		free(table->philos);
	}
	return (status);
}