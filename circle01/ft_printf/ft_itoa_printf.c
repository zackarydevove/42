/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:20:06 by zdevove           #+#    #+#             */
/*   Updated: 2022/11/18 14:11:30 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_length(long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		len++;
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*tolong(char *str, int i, long nb)
{
	while (nb > 0)
	{
		str[i] = (nb % 10) + 48;
		nb /= 10;
		i--;
	}
	return (str);
}

int	ft_itoa_printf(int n)
{
	char	*str;
	int		i;
	long	nb;

	nb = n;
	i = get_length(nb);
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (0);
	str[i--] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	str = tolong(str, i, nb);
	ft_putstr_printf(str);
	i = ft_strlen(str);
	free(str);
	return (i);
}
