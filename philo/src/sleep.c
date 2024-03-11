/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:08:03 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/11 16:22:50 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long	get_time(struct timeval start, struct timeval now)
{
	return (start.tv_sec + now.tv_sec) 
}

void	precise_usleep(long usec)
{
	struct timeval start;
	struct timeval now;

	gettimeofday(&start, NULL);
}
