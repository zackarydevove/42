/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:55:08 by zdevove           #+#    #+#             */
/*   Updated: 2023/05/16 11:09:16 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}

long long	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->writing);
	if (!routine_stop(philo->data))
		printf("%lld %d %s\n", timestamp() - philo->data->start_time,
			philo->num, str);
	pthread_mutex_unlock(&philo->data->writing);
}

void	ft_usleep(long long time_to_x)
{
	long long	start;

	start = timestamp();
	while ((timestamp() - start) < time_to_x)
		usleep(50);
}

void	sync_threads(long long start_time)
{
	while (timestamp() < start_time)
		usleep(100);
}
