#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct s_data t_data;

typedef struct s_philo
{
	t_data *data;
	pthread_t		pthread;
	pthread_mutex_t	philo_mutex;
	int				num;
	int				eat_time;
	int				lfork;
	int				rfork;
	long long		last_meal;
}				t_philo;

typedef struct s_data
{
	t_philo			*philo;
	pthread_t		check_d_thread;
	pthread_mutex_t	*forks;
	pthread_mutex_t	writing;
	pthread_mutex_t	meal;
	pthread_mutex_t	stop_mutex;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eat;
	int				stop;
	long long		start_time;
}				t_data;

int			data_init(t_data *data, char **av);

void		*routine(void *ph);
void		*death_routine(void *data);

int			routine_stop(t_data *data);
void		destroy_mutex(t_data *data);
int			philo_start(t_data *data);

int			ft_atoi(const char *str);
long long	timestamp(void);
void		ft_usleep(int nb_philo, long long time_to_x);
void		ft_print(t_philo *p, char *str);
void		sync_threads(long long start_time);
int			write_error(char *str);

#endif