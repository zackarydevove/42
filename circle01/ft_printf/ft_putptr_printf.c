/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:59:44 by zdevove           #+#    #+#             */
/*   Updated: 2022/11/18 14:00:03 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexlen(uintptr_t p)
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

void	ft_putptr_recursive(uintptr_t p)
{
	if (p >= 16)
	{
		ft_putptr_recursive(p / 16);
		ft_putptr_recursive(p % 16);
	}
	else
	{
		if (p <= 9)
			ft_putchar_printf(p + 48);
		else
			ft_putchar_printf(p - 10 + 'a');
	}
}

int	ft_put_ptr_printf(uintptr_t p)
{
	int	len;

	len = 0;
	if (p == 0)
		return (ft_putstr_printf("(nil)"));
	len += ft_putstr_printf("0x");
	len += hexlen(p);
	ft_putptr_recursive(p);
	return (len);
}
