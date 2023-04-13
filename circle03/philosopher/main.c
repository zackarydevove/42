/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:48:38 by zdevove           #+#    #+#             */
/*   Updated: 2023/02/03 10:07:20 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void    free_all(t_data *data)
{
    int i;

    i = -1;
    while (++i < (int)data->nb_philo)
        pthread_mutex_destroy(&data->fork[i]);
    free(data->philo);
    free(data->fork);
    free(data);   
}

int	write_error(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	write(2, "Error: ", 7);
	write(2, str, len);
	write(2, "\n", 1);
	return (1);
}

int main(int ac, char **av)
{
    t_data  *data;

    if (ac == 5 || ac == 6 )
    {
        // Check si tous les arguments sont bien des chiffres entre 0 and 9
        if (!check_av(av))
            return (write_error("Invalid arguments"), 0);
        data = malloc(sizeof(t_data));
        if (!data)
            return (0);
        if (!data_init(data, av))
            return (write_error("Data_init error"), 0);
        if (!philo_init(data))
            return (free_all(data), write_error("Philo_init error"), 0);
        free_all(data);
    }
    else
        write_error("Need 4 or 5 arguments");
    return (0);
}