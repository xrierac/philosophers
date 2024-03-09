/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:04:08 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/09 16:26:17 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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
