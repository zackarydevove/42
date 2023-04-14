/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoaunsigned_printf.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 11:48:12 by zdevove           #+#    #+#             */
/*   Updated: 2022/11/18 14:00:57 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_length_unsigned(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		len++;
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int	ft_itoaunsigned_printf(unsigned int nb)
{
	char	*str;
	int		i;

	i = get_length_unsigned(nb);
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (0);
	str[i--] = '\0';
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[i] = (nb % 10) + 48;
		nb /= 10;
		i--;
	}
	ft_putstr_printf(str);
	i = ft_strlen(str);
	free(str);
	return (i);
}
