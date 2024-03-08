/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:39:52 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/08 17:26:07 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
}	t_philo;

typedef struct s_table
{
	int		nbrphilo;
	long	tdie;
	long	teat;
	long	tsleep;
	long	nbreat;
}	t_table;

//Parsing//
int		parse_input(char *argv[], int argc, t_table *table);
size_t	ft_strlen(char *str);
long	ft_atol(char *str);

//Utils//
void	ft_putstr_fd(char *s, int fd);

#endif
