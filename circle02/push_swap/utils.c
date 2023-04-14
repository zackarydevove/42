/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 09:34:38 by zdevove           #+#    #+#             */
/*   Updated: 2022/12/26 12:10:22 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Check if stack is sorted
int	issorted(t_stack **stack)
{
	t_stack	*lst;

	lst = *stack;
	while (lst->n)
	{
		if (lst->number < lst->n->number)
			return (0);
		lst = lst->n;
	}
	return (1);
}

// Check if stack is empty
int	isempty(t_stack **stack)
{
	if (!*stack)
		return (1);
	else
		return (0);
}

// Check if there is doubles in av
int	isdouble(char **av, int nb, int i)
{
	i++;
	while (av[i] != 0)
	{
		if (ft_atoi(av[i]) == nb)
			return (1);
		i++;
	}
	return (0);
}

int	isnumber(char *s)
{
	int	i;

	i = 0;
	if (s && s[0] == '-')
		i++;
	while (s[i] != '\0')
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ftt_free_av(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	while (i--)
		free(av[i]);
}
