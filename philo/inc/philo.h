/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:39:52 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/11 16:22:57 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>

typedef struct s_philo
{
	pthread_t	thread;
	int			id;
	int			meals;
}	t_philo;

typedef struct s_sim
{
	int		n_phil;
	int		tdie;
	int		teat;
	int		tsleep;
	int		n_eat;
	int		start_time;
	t_philo	**phteam;
}	t_sim;

//Initialize//
t_sim	*init_sim(int argc, char *argv[]);

//Parsing//
int		parse_input(char *argv[], int argc, t_sim *sim);
size_t	ft_strlen(char *str);
long	ft_atol(char *str);

//Utils//
void	ft_putstr_fd(char *s, int fd);

//Exit//
void	exit_error(char *str, t_sim *sim);

#endif
