/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:54:46 by zdevove           #+#    #+#             */
/*   Updated: 2023/05/16 11:29:47 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	routine_stop(t_data *data)
{
	int	status;

	pthread_mutex_lock(&data->stop_mutex);
	status = data->stop;
	pthread_mutex_unlock(&data->stop_mutex);
	return (status);
}

static void	set_stop(t_data *data, int status)
{
	pthread_mutex_lock(&data->stop_mutex);
	data->stop = status;
	pthread_mutex_unlock(&data->stop_mutex);
}

static int	philo_finish(t_data *data)
{
	int		i;
	int		everyone_ate;

	i = -1;
	everyone_ate = 1;
	while (++i < data->nb_philo)
	{
		pthread_mutex_lock(&data->philo[i].philo_mutex);
		if (timestamp() - data->philo[i].last_meal > data->time_to_die)
		{
			ft_print(&data->philo[i], "died");
			set_stop(data, 1);
			pthread_mutex_unlock(&data->philo[i].philo_mutex);
			return (1);
		}
		if (data->nb_must_eat > -1
			&& data->philo[i].eat_time < data->nb_must_eat)
			everyone_ate = 0;
		pthread_mutex_unlock(&data->philo[i].philo_mutex);
	}
	if (data->nb_must_eat != -1 && everyone_ate)
		return (set_stop(data, 1), 1);
	return (0);
}

void	*death_routine(void *d)
{
	t_data	*data;

	data = (t_data *)d;
	sync_threads(data->start_time);
	while (!philo_finish(data))
		usleep(900);
	return (0);
}
