/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:39:52 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/20 14:40:45 by xriera-c         ###   ########.fr       */
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
# define ERR_MUTEX_I	"Mutex initialization failed\n"
# define ERR_TIME		"Time function failed\n"
# define ERR_COL_THR	"Closing threads failed\n"
# define ERR_MUTEX_D	"Mutex destruction failed\n"

typedef struct s_table	t_table;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				n_meals;
	long			last_meal;
	int				forks[2];
	pthread_mutex_t	meal_lock;
	t_table			*table;
}	t_philo;

typedef struct s_table
{
	int				n_phil;
	long			tdie;
	long			teat;
	long			tsleep;
	long			must_eat;
	long			start_time;
	int				finish;
	t_philo			**philos;
	pthread_mutex_t	*forks_lock;
	pthread_t		watch;
}	t_table;

typedef enum e_status
{
	DIED = 0,
	EATING = 1,
	SLEEP = 2,
	THINK = 3,
	GOT_FORK = 4,
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

//Mutexes//
int		init_forks(t_table *table);
int		init_mutexes(t_table *table);
int		destroy_forks(t_table *table, int index);
int		destroy_mutexes(t_table *table, int index);

//Threads//
int		start_philo(t_table *table);
void	*main_routine(void *arg);
int		collect_threads(t_table *table, int index);
void	*watchdog(void *arg);

//Utils//
long	get_time(void);
void	precise_usleep_ms(long time);
void	ft_putstr_fd(char *s, int fd);
void	print_change(t_philo *philo, t_status status);

//Exit//
int		ft_exit(char *s, t_table *table, t_status status);

#endif
