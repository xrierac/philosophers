/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:41:00 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/14 16:37:12 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char *argv[])
{
	t_table	table;

	if (argc != 5 && argc != 6)
		return (ft_exit(ERR_ARG_NUM, NULL, ERROR));
	if (init_table(argc, argv, &table) == -1)
		return (-1);
	if (start_philo(&table) != 0)
		return (-1);
	destroy_mutexes(&table, table.n_phil - 1);
	return (ft_exit(NULL, &table, SUCCESS));
}
