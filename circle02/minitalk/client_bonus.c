/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:09:20 by zdevove           #+#    #+#             */
/*   Updated: 2023/01/02 13:40:10 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int	g_isleep = 1;

void	ft_handler(int signal)
{
	g_isleep = 0;
}

// Send char to server bit by bit through signals
void	send_bits(int c, int server_pid)
{
	int	bit;

	bit = 8;
	while (bit)
	{
		if ((c >> (bit - 1)) & 1)
		{
			if (kill(server_pid, SIGUSR1) == -1)
				return ;
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				return ;
		}
		bit--;
		while (g_isleep)
			usleep(50);
		g_isleep = 1;
	}
}

// Receive Server_pid and send string char by char
int	main(int ac, char **av)
{
	int					i;
	struct sigaction	sa;

	if (ac == 3)
	{
		sa.sa_handler = ft_handler;
		sigaction(SIGUSR1, &sa, NULL);
		i = 0;
		while (av[2][i])
		{
			send_bits(av[2][i], ft_atoi(av[1]));
			i++;
		}
		send_bits(0, ft_atoi(av[1]));
	}
	return (0);
}
