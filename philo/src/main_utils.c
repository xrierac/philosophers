/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:04:08 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/12 13:43:11 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

t_sim	*free_sim(t_sim *sim)
{
	int	i;

	i = -1;
	if (sim->phteam != NULL)
	{
		while (sim->phteam[++i])
		{
			pthread_mutex_destroy(&sim->phteam[i]->meal_lock);
			free(sim->phteam[i]);
		}
		free(sim->phteam);
	}
	if (sim != NULL)
		free(sim);
	return (NULL);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s && fd)
	{
		while (*s)
		{
			write(fd, s, 1);
			s++;
		}
	}
}
