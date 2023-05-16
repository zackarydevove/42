/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:55:05 by zdevove           #+#    #+#             */
/*   Updated: 2023/05/16 11:15:00 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	ft_take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->lfork]);
	ft_print(philo, "has taken a fork");
	pthread_mutex_lock(&philo->data->forks[philo->rfork]);
	ft_print(philo, "has taken a fork");
}

static void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_mutex);
	ft_print(philo, "is eating");
	philo->last_meal = timestamp();
	ft_usleep(philo->data->time_to_eat);
	philo->eat_time++;
	pthread_mutex_unlock(&philo->philo_mutex);
	pthread_mutex_unlock(&philo->data->forks[philo->rfork]);
	pthread_mutex_unlock(&philo->data->forks[philo->lfork]);
}

void	*routine(void *ph)
{
	t_philo		*philo;

	philo = (t_philo *)ph;
	pthread_mutex_lock(&philo->philo_mutex);
	philo->last_meal = philo->data->start_time;
	pthread_mutex_unlock(&philo->philo_mutex);
	sync_threads(philo->data->start_time);
	if (!(philo->num % 2))
	{
		ft_print(philo, "is thinking");
		ft_usleep(philo->data->time_to_eat / 10);
	}
	while (!routine_stop(philo->data))
	{
		ft_take_forks(philo);
		ft_eat(philo);
		ft_print(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep);
		ft_print(philo, "is thinking");
	}
	return (0);
}
