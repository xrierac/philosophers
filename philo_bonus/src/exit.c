/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:26:34 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/21 14:39:34 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

int	ft_exit(char *s, t_table *table, t_status status)
{
	if (status == ERROR)
		ft_putstr_fd(s, 2);
	return (status)
}
