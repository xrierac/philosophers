/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:41:00 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/08 12:09:31 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_error(char *str)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
		exit_error("Wrong number of arguments\n");
	if (parse_input(argv) < 0)
		exit_error("Wrong arguments\n");
	return (0);
}
