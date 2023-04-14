/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:37:27 by zdevove           #+#    #+#             */
/*   Updated: 2022/11/18 14:01:58 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

int		ft_putchar_printf(char c);

size_t	ft_strlen(const char *s);

int		ft_putstr_printf(char *s);

int		ft_put_ptr_printf(uintptr_t p);

int		ft_putx_printf(unsigned int p, const char c);

int		ft_itoaunsigned_printf(unsigned int nb);

int		ft_itoa_printf(int n);

int		check_pourcent(const char c, va_list args);

int		ft_printf(const char *s, ...);

#endif
