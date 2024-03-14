/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:39:52 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/14 11:04:40 by xriera-c         ###   ########.fr       */
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

# define ERR_MALLOC 	"Memory allocation failed\n"
# define ERR_ARG_NUM	"Invalid number of arguments\n"
# define ERR_ARG		"Invalid argument\n"
# define ERR_MUTEX		"Mutex failed\n"

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				n_meals;
	int				last_meal;
	int				forks[2];
	pthread_mutex_t	meal_lock;
}	t_philo;

typedef struct s_table
{
	int		n_phil;
	int		tdie;
	int		teat;
	int		tsleep;
	int		must_eat;
	int		start_time;
	t_philo	**philos;
}	t_table;

typedef enum e_status
{
	DIED = 0,
	EATING = 1,
	SLEEP = 2,
	THINK = 3,
	GOT_FORK = 4,
	INIT = 1,
	DESTROY = 2,
	ERROR = -1,
	SUCCESS = 0
}	t_status;

//Initialize//
int		init_table(int argc, char *argv[], t_table *table);
int		sit_philos(t_table *table);
void	init_philos(t_table *table);

//Parsing//
int		parse_input(char *argv[], int argc, t_table *table);
size_t	ft_strlen(char *str);
long	ft_atol(char *str);

//Routines//
void	philo_routine(void *arg);

//Utils//
void	ft_putstr_fd(char *s, int fd);
t_table	*free_table(t_table *table);

//Exit//
int	ft_exit(char *s, t_table *table, t_status status);

#endif
