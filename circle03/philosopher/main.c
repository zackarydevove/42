/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:54:51 by zdevove           #+#    #+#             */
/*   Updated: 2023/05/16 11:08:45 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	write_error(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(2, "Error: ", 7);
	write(2, str, len);
	write(2, "\n", 1);
	return (1);
}

static int	check_av(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = -1;
		if (!ft_atoi(av[i]) || ft_atoi(av[i]) < 0)
			return (0);
		while (av[i][++j])
			if (av[i][j] < '0' && av[i][j] > '9')
				return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		if (!check_av(av))
			return (write_error("Invalid arguments"), 0);
		if (ft_atoi(av[1]) == 1)
			return (printf("%d 1 died\n", ft_atoi(av[2])), 0);
		if (!data_init(&data, av))
			return (write_error("Data_init error"), 0);
		if (philo_start(&data))
			return (destroy_mutex(&data), write_error("Philo_init error"), 0);
		destroy_mutex(&data);
	}
	else
		write_error("Need 4 or 5 arguments");
	return (1);
}
