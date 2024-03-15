/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:04:28 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/15 17:13:30 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	philo_eat(t_philo *philo)
{
	if (get_time() - philo->last_meal <= philo->table->tdie)
	{
		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(&philo->table->forks_lock[philo->forks[0]]);
			print_change(philo, GOT_FORK);
		}
		pthread_mutex_lock(&philo->table->forks_lock[philo->forks[1]]);
		print_change(philo, GOT_FORK);
		if (philo->id % 2)
		{
			pthread_mutex_lock(&philo->table->forks_lock[philo->forks[0]]);
			print_change(philo, GOT_FORK);
		}
		philo->last_meal = get_time();
		print_change(philo, EATING);
		precise_usleep(philo->table->teat);
		pthread_mutex_unlock(&philo->table->forks_lock[philo->forks[0]]);
		pthread_mutex_unlock(&philo->table->forks_lock[philo->forks[1]]);
		philo->n_meals++;
	}
	else
	{
		philo->table->finish = 1;
		print_change(philo, DIED);
	}
}

static void	sleep_routine(t_philo *philo)
{
	print_change(philo, SLEEP);
	precise_usleep(philo->table->tsleep);
}

static void	think_routine(t_philo *philo)
{
	print_change(philo, THINK);
	precise_usleep(1);
}

void	*main_routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->table->tdie == 0)
		return (NULL);
	philo->last_meal = philo->table->start_time;
	if (philo->id % 2)
		precise_usleep(5);
	while (philo->table->finish == 0)
	{
		philo_eat(philo);
		if (philo->n_meals >= philo->table->must_eat
			   	&& philo->table->must_eat > 0)
			break ;
		if (philo->table->finish == 0)
			sleep_routine(philo);
		if (philo->table->finish == 0)
			think_routine(philo);
	}
	return (NULL);
}
