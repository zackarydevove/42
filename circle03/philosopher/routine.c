#include "philosopher.h"

// Takes forks, if there is only one philo, quit
static int	ft_take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->lfork]);
	ft_print(philo, "has taken a fork");
	if (philo->data->nb_philo == 1)
		return (ft_usleep(philo->data->nb_philo, philo->data->time_to_die + 10), 1);
	pthread_mutex_lock(&philo->data->forks[philo->rfork]);
	ft_print(philo, "has taken a fork");
	return (0);
}

static void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_mutex);
	ft_print(philo, "is eating");
	philo->last_meal = timestamp();
	ft_usleep(philo->data->nb_philo, philo->data->time_to_eat);
	philo->eat_time++;
	pthread_mutex_unlock(&philo->philo_mutex);
	pthread_mutex_unlock(&philo->data->forks[philo->rfork]);
	pthread_mutex_unlock(&philo->data->forks[philo->lfork]);
}

// Sync_thread usleep until time met to start at same time for everyone
// philo->num % 2 prevent deadlock and ensure odd-number can have a fork
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
		ft_usleep(philo->data->nb_philo, philo->data->time_to_eat / 10);
	}
	while (!routine_stop(philo->data))
	{
		if (ft_take_forks(philo))
			return (0);
		ft_eat(philo);
		ft_print(philo, "is sleeping");
		ft_usleep(philo->data->nb_philo, philo->data->time_to_sleep);
		ft_print(philo, "is thinking");
	}
	return (0);
}
