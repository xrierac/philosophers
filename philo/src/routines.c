/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:04:28 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/20 14:42:11 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	philo_eat(t_philo *philo)
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
	print_change(philo, EATING);
	philo->last_meal = get_time();
	precise_usleep_ms(philo->table->teat);
	pthread_mutex_unlock(&philo->table->forks_lock[philo->forks[0]]);
	pthread_mutex_unlock(&philo->table->forks_lock[philo->forks[1]]);
}

static void	sleep_routine(t_philo *philo)
{
	print_change(philo, SLEEP);
	precise_usleep_ms(philo->table->tsleep);
}

static void	think_routine(t_philo *philo)
{
	print_change(philo, THINK);
	precise_usleep_ms(philo->table->teat - philo->table->tsleep);
}

static void	misanthrope(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks_lock[philo->forks[0]]);
	print_change(philo, GOT_FORK);
	precise_usleep_ms(philo->table->tdie);
	philo->table->finish = 1;
	pthread_mutex_unlock(&philo->table->forks_lock[philo->forks[0]]);
}

void	*main_routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->table->tdie == 0)
		return (NULL);
	philo->last_meal = philo->table->start_time;
	if (philo->table->n_phil == 1)
		misanthrope(philo);
	if (philo->id % 2)
		precise_usleep_ms(5);
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
