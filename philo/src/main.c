/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:41:00 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/13 13:56:21 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	exit_success(t_table *table)
{
	free_table(table);
	exit(EXIT_SUCCESS);
}

void	exit_error(char *str, t_table *table)
{
	free_table(table);
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

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

int	main(int argc, char *argv[])
{
	t_table	*table;

	if (argc != 5 && argc != 6)
		exit_error(ERR_ARG_NUM, NULL);
	table = init_table(argc, argv);
	exit_success(table);
	return (0);
}
