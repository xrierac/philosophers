/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:10:26 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/15 11:33:09 by xriera-c         ###   ########.fr       */
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

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long	ft_atol(char *str)
{
	long	i;

	i = 0;
	while (*str == ' ')
		str++;
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		i = (i * 10) + (*str - '0');
		str++;
	}
	if (*str != '\0')
		return (-1);
	return (i);
}
