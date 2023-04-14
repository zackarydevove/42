/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:35:42 by zdevove           #+#    #+#             */
/*   Updated: 2023/01/01 10:31:30 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ftt_lstadd_front(t_stack **lst, t_stack *new)
{
	new->n = (*lst);
	(*lst) = new;
}

int	check_av(int ac, char ***av)
{
	int		i;
	long	t;

	i = 1;
	if (ac == 2)
	{
		*av = ft_split((*av)[1], ' ');
		if (!(*av))
			return (0);
		i = 0;
	}
	while ((*av)[i])
	{
		t = (long)ft_atoi((*av)[i]);
		if (ismaxint((*av)[i]) || !isnumber((*av)[i]) || \
			isdouble((*av), ft_atoi((*av)[i]), i))
		{
			ft_putendl_fd("Error", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

t_stack	*get_next_min(t_stack **stack_a)
{
	t_stack	*head;
	t_stack	*min;

	head = *stack_a;
	while (head && head->i != -1)
		head = head->n;
	min = head;
	while (head)
	{
		if (head->i == -1 && head->number < min->number)
			min = head;
		head = head->n;
	}
	return (min);
}

int	avlen(char **av, int ac)
{
	int	i;

	i = 0;
	if (ac != 2)
		return (0);
	while (av[i] != 0)
		i++;
	return (i);
}

void	put_value_in(t_stack **stack_a, char **av, int ac)
{
	int		i;
	t_stack	*new;

	i = 1;
	if (ac == 2)
		i = 0;
	while (av[i])
	{
		new = ftt_lstnew(ft_atoi(av[i]));
		if (!new)
			return ;
		ftt_lstadd_front(stack_a, new);
		i++;
	}
	i = 0;
	while (i < (int []){ac - 1, avlen(av, ac)}[(ac == 2)])
	{
		new = get_next_min(stack_a);
		new->i = i++;
	}
}
