/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:41:00 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/14 12:35:31 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
void	mutexes(t_table *table, t_status status)
{
	int	i;
	int	value;

	i = 0;
	while (table->philos[i])
	{
		if (status == INIT)
			value = pthread_mutex_init(table->philos[i]->meal_lock);
		if (status == DESTROY)
			value = pthread_mutex_destroy(table->philos[i]->meal_lock);
		if (value)
			exit_error(ERR_MUTEX, table);
		i++;
	}
}

void	start_meal(t_table *table)
{
	mutexes(table, INIT);

}
*/
int	main(int argc, char *argv[])
{
	t_table	table;

	if (argc != 5 && argc != 6)
		return (ft_exit(ERR_ARG_NUM, NULL, ERROR));
	if (init_table(argc, argv, &table) == -1)
		return (-1);
	return (ft_exit(NULL, &table, SUCCESS));
}
