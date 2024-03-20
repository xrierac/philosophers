/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:41:00 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/20 17:03:22 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char *argv[])
{
	t_table	table;

	if (argc != 5 && argc != 6)
		return (ft_exit(ERR_ARG_NUM, NULL, ERROR));
	if (argc == 6 && argv[5] == 0)
		return (0);
	if (init_table(argc, argv, &table) == -1)
		return (-1);
	if (start_philo(&table) != 0)
		return (-1);
	collect_threads(&table, table.n_phil - 1);
	pthread_join(table.watch, NULL);
	destroy_forks(&table, table.n_phil - 1);
	if (destroy_mutexes(&table, table.n_phil - 1) > 0)
		return (ft_exit(ERR_MUTEX_D, &table, ERROR));
	return (ft_exit(NULL, &table, SUCCESS));
}
