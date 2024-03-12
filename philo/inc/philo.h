/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:39:52 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/12 12:07:50 by xriera-c         ###   ########.fr       */
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
	pthread_t		thread;
	int				id;
	int				n_meals;
	int				last_meal;
	pthread_mutex_t	meal_lock;
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
t_philo	**init_team(t_sim *sim);

//Parsing//
int		parse_input(char *argv[], int argc, t_sim *sim);
size_t	ft_strlen(char *str);
long	ft_atol(char *str);

//Utils//
void	ft_putstr_fd(char *s, int fd);
t_sim	*free_sim(t_sim *sim);

//Exit//
void	exit_error(char *str, t_sim *sim);

#endif
