/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:01:27 by zdevove           #+#    #+#             */
/*   Updated: 2023/01/02 13:40:21 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int	g_tab[1000000];

// Convert binary to char ==> i * 128, i+1 * 64, i+2 * 32, ...
int	get_next_char(int j)
{
	int	i;
	int	res;
	int	mult;

	i = 0;
	res = 0;
	mult = 128;
	while (i <= 8)
	{
		res += g_tab[j + i] * mult;
		i++;
		mult /= 2;
	}
	return (res);
}

// Fulfill the string
void	tab_int_to_str(void)
{
	int		len;
	int		i;
	char	*str;

	len = 0;
	i = 0;
	while (g_tab[len] != 2)
		len++;
	str = malloc(((len / 8)) * sizeof(char));
	if (!str)
		return ;
	while (i < len / 8)
	{
		str[i] = get_next_char(i * 8);
		i++;
	}
	ft_putendl_fd(str, 1);
	free(str);
}

void	reset(void)
{
	int	i;

	i = 0;
	while (i < 1000000)
		g_tab[i++] = 2;
}

// Receive signals from client, add 1 if SIGUSR1, add 0 if SIGUSR2
void	ft_handler(int signal, siginfo_t *info)
{
	int	i;
	int	count;

	i = 0;
	while (g_tab[i] != 2)
		i++;
	if (signal == SIGUSR1)
		g_tab[i] = 1;
	else if (signal == SIGUSR2)
		g_tab[i] = 0;
	kill(info->si_pid, SIGUSR1);
	if ((i + 1) % 8 == 0)
	{
		count = 0;
		while (count < 8 && g_tab[i - count] == 0)
			count++;
		if (count == 8)
		{
			tab_int_to_str();
			reset();
		}
	}
	return ;
}

// Print server pid and set the signals handlers
int	main(int ac, char **av)
{
	struct sigaction	sa;
	struct sigaction	sb;

	(void) av;
	if (ac == 1)
	{
		reset();
		sa.sa_flags = SA_SIGINFO;
		sb.sa_flags = SA_SIGINFO;
		sa.sa_handler = (void *)ft_handler;
		sb.sa_handler = (void *)ft_handler;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sb, NULL);
		ft_putstr_fd("server PID: ", 1);
		ft_putnbr_fd(getpid(), 1);
		write(1, "\n", 1);
		while (1)
			pause();
	}
	return (0);
}
