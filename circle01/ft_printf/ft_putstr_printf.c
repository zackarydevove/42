/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:19:49 by zdevove           #+#    #+#             */
/*   Updated: 2022/11/18 14:02:44 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putstr_printf(char *s)
{
	int	i;

	if (!s)
		s = "(null)";
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_printf(s[i]);
		i++;
	}
	return (i);
}
