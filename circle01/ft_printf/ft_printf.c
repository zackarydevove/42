/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:57:12 by zdevove           #+#    #+#             */
/*   Updated: 2022/11/18 13:59:27 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_pourcent(const char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar_printf(va_arg(args, int));
	if (c == 's')
		len += ft_putstr_printf(va_arg(args, char *));
	if (c == 'p')
		len += ft_put_ptr_printf(va_arg(args, uintptr_t));
	if (c == 'd' || c == 'i')
		len += ft_itoa_printf(va_arg(args, int));
	if (c == 'u')
		len += ft_itoaunsigned_printf(va_arg(args, unsigned int));
	if (c == 'x' || c == 'X')
		len += ft_putx_printf(va_arg(args, unsigned int), c);
	if (c == '%')
		len += ft_putchar_printf(37);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			len += check_pourcent(s[i], args);
		}
		else
			len += ft_putchar_printf((int)s[i]);
		i++;
	}
	va_end(args);
	return (len);
}
