/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:00:18 by zdevove           #+#    #+#             */
/*   Updated: 2022/11/18 14:00:30 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexlenx(unsigned int p)
{
	int	i;

	i = 0;
	if (p == 0)
		i++;
	while (p > 0)
	{
		p /= 16;
		i++;
	}
	return (i);
}

void	ft_putx_recursive(unsigned int p, const char c)
{
	if (p >= 16)
	{
		ft_putx_recursive(p / 16, c);
		ft_putx_recursive(p % 16, c);
	}
	else
	{
		if (p <= 9)
			ft_putchar_printf(p + 48);
		else
		{
			if (c == 'x')
				ft_putchar_printf(p - 10 + 'a');
			if (c == 'X')
				ft_putchar_printf(p - 10 + 'A');
		}
	}
}

int	ft_putx_printf(unsigned int p, const char c)
{
	int	len;

	len = 0;
	if (p == 0)
		return (ft_putchar_printf('0'));
	len += hexlenx(p);
	ft_putx_recursive(p, c);
	return (len);
}
