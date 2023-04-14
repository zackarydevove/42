/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 10:14:42 by zdevove           #+#    #+#             */
/*   Updated: 2023/01/06 11:15:46 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ismaxint(char *s)
{
	int		i;
	int		j;
	char	*cmp;

	cmp = "-2147483647";
	i = 0;
	j = 0;
	if (ft_strlen(s) > 11)
		return (1);
	else if (ft_strlen(s) < 10 || ft_strncmp(s, "-2147483648", 11) == 0
		|| (s[0] == '-' && ft_strlen(s) == 10))
		return (0);
	if (s[0] != '-')
		j = 1;
	while (s[i] != '\0')
	{
		if (s[i] > cmp[j])
			return (1);
		j++;
		i++;
	}
	return (0);
}
