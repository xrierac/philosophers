/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:04:28 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/20 16:59:58 by xriera-c         ###   ########.fr       */
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
	pthread_mutex_lock(&philo->time_lock);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->time_lock);
	precise_usleep_ms(philo->table->teat);
	pthread_mutex_unlock(&philo->table->forks_lock[philo->forks[0]]);
	pthread_mutex_unlock(&philo->table->forks_lock[philo->forks[1]]);
	pthread_mutex_lock(&philo->meal_lock);
	philo->n_meals++;
	pthread_mutex_unlock(&philo->meal_lock);
	print_change(philo, SLEEP);
	precise_usleep_ms(philo->table->tsleep);
}

static void	think_routine(t_philo *philo)
{
	print_change(philo, THINK);
	precise_usleep_ms(philo->table->teat - (philo->table->tsleep / 2));
}

static void	misanthrope(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks_lock[philo->forks[0]]);
	print_change(philo, GOT_FORK);
	precise_usleep_ms(philo->table->tdie);
	pthread_mutex_lock(&philo->table->dead_lock);
	philo->table->finish = 1;
	pthread_mutex_unlock(&philo->table->dead_lock);
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
		precise_usleep_ms(philo->table->teat);
	while (philo->table->finish == 0)
	{
		philo_eat(philo);
		think_routine(philo);
		if (philo->n_meals >= philo->table->must_eat
			&& philo->table->must_eat > 0)
			break ;
	}
	return (NULL);
}
