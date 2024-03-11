/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:41:00 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/11 12:30:53 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	exit_success(t_sim *sim)
{
	free(sim);
	exit(EXIT_SUCCESS);
}

void	exit_error(char *str, t_sim *sim)
{
	if (sim != NULL)
		free(sim);
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_sim	*sim;

	if (argc != 5 && argc != 6)
		exit_error("Wrong number of arguments\n", NULL);
	sim = init_sim(argc, argv);
	exit_success(sim);
	return (0);
}
