/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:44:29 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/15 12:21:03 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	print_change(t_philo *philo, t_status status)
{
	if (status == GOT_FORK)
		printf("%d %d has taken a fork\n", get_time() - 
				philo->table->start_time, philo->id);
	if (status == EATING)
		printf("%d %d is eating\n", get_time() - philo->table->start_time,
				philo->id);
	if (status == THINK)
		printf("%d %d is thinking\n", get_time() - philo->table->start_time,
				philo->id);
	if (status == DIED)
		printf("%d %d died\n", get_time() - philo->table->start_time,
				philo->id);
	if (status == SLEEP)
		printf("%d %d is sleeping\n", get_time() - philo->table->start_time,
				philo->id);
}
