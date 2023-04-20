#include "philosopher.h"

void	destroy_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philo[i].philo_mutex);
	}
	free(data->philo);
	free(data->forks);
	if (pthread_mutex_destroy(&data->writing))
		write_error("error destroy data->write mutex");
	if (pthread_mutex_destroy(&data->meal))
		write_error("error destroy data->meal mutex");
	if (pthread_mutex_destroy(&data->stop_mutex))
		write_error("error destroy data->stop_mutex mutex");
}

// Create a thread that will do death_routine to check if a philo died
// Pthread_join will wait for the thread to finish its routine to join
int	join_thread(t_data *data)
{
	int	i;

	i = -1;
	if (pthread_create(&data->check_d_thread, 0, &death_routine, data))
		return (0);
	while (++i < data->nb_philo)
		if (pthread_join(data->philo[i].pthread, 0))
			return (0);
	return (!pthread_join(data->check_d_thread, 0) ? 0 : 1);
}


// Create threads ans start routines
// Set a starting time to synchronize on
int	philo_start(t_data *data)
{
	int	i;

	i = -1;
	data->start_time = timestamp() + (data->nb_philo * 20);
	while (++i < data->nb_philo)
		if (pthread_create(&data->philo[i].pthread, 0
				, &routine, &data->philo[i]))
			return (write_error("error philo_start at pthread create"), 0);
	return (!join_thread(data) ? 0 : 1);
}
