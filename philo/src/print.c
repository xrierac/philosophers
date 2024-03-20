/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:44:29 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/20 11:43:54 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	print_change(t_philo *philo, t_status status)
{
	if (philo->table->finish == 0)
	{
		if (status == GOT_FORK)
			printf("%ld %d has taken a fork\n", (get_time()
					- philo->table->start_time), philo->id);
		if (status == EATING)
			printf("%ld %d is eating\n", get_time() - philo->table->start_time,
				philo->id);
		if (status == THINK)
			printf("%ld %d is thinking\n", get_time()
				- philo->table->start_time, philo->id);
		if (status == SLEEP)
			printf("%ld %d is sleeping\n", get_time()
				- philo->table->start_time, philo->id);
	}
	if (status == DIED)
		printf("%ld %d died\n", get_time() - philo->table->start_time,
			philo->id);
}
