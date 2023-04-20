#include "philosopher.h"

static int	philo_init(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
	{
		data->philo[i].num = i + 1;
		data->philo[i].eat_time = 0;
		data->philo[i].lfork = i;
		data->philo[i].rfork = (i + 1) % data->nb_philo;
		if (!(data->philo[i].num % 2))	// ?
		{
			data->philo[i].lfork = (i + 1) % data->nb_philo;
			data->philo[i].rfork = i;
		}
		data->philo[i].data = data;
		data->philo[i].last_meal = timestamp();
	}
	return (1);
}

static int	mutex_init(t_data *data)
{
	int	i;

	i = -1;
	data->forks = malloc(data->nb_philo * sizeof(pthread_mutex_t));
	if (!data->forks)
		return (0);
	while (++i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->forks[i], 0))
			return (write_error("error forks mutex init"), 0);
		if (pthread_mutex_init(&(data->philo[i].philo_mutex), 0)) // on a un mutex pour pas faire 2 chose en meme temps quand on check la mort du philo
			return (write_error("error philo_start mutex init"), 0);
	}
	if (pthread_mutex_init(&data->writing, 0))
		return (write_error("error writing mutex init"), 0);
	if (pthread_mutex_init(&data->meal, 0))
		return (write_error("error meal mutex init"), 0);
	if (pthread_mutex_init(&data->stop_mutex, 0))
		return (write_error("error stop mutex init"), 0);
	return (philo_init(data));
}

int	data_init(t_data *data, char **av)
{
	data->nb_philo = ft_atoi(av[1]);
	if (data-> nb_philo < 1)
		return (0);
	data->philo = malloc(data->nb_philo * sizeof(t_philo));
	if (!data->philo)
		return (0);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data->nb_must_eat = ft_atoi(av[5]);
	else
		data->nb_must_eat = -1;
	data->stop = 0;
	if (!mutex_init(data))
		return (free(data->philo), 0);
	return (1);
}
