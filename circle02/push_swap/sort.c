/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:47:30 by zdevove           #+#    #+#             */
/*   Updated: 2022/12/28 08:06:50 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **stack_a)
{
	if ((*stack_a)->i < (*stack_a)->n->i && (*stack_a)->n->i < (*stack_a)-> \
			n->n->i && (*stack_a)->n->n->i > (*stack_a)->i)
	{
		ra(stack_a);
		sa(stack_a);
	}
	if ((*stack_a)->i < (*stack_a)->n->i && (*stack_a)->n->i > (*stack_a)-> \
			n->n->i && (*stack_a)->n->n->i > (*stack_a)->i)
		rra(stack_a);
	if ((*stack_a)->i > (*stack_a)->n->i && (*stack_a)->n->i < (*stack_a)-> \
			n->n->i && (*stack_a)->n->n->i > (*stack_a)->i)
		ra(stack_a);
	if ((*stack_a)->i < (*stack_a)->n->i && (*stack_a)->n->i > (*stack_a)-> \
			n->n->i && (*stack_a)->n->n->i < (*stack_a)->i)
	{
		rra(stack_a);
		sa(stack_a);
	}
	if ((*stack_a)->i > (*stack_a)->n->i && (*stack_a)->n->i < (*stack_a)-> \
			n->n->i && (*stack_a)->n->n->i < (*stack_a)->i)
		sa(stack_a);
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->i == 0)
			break ;
		i++;
		tmp = tmp->n;
	}
	if (i == 0)
		rra(stack_a);
	if (i == 1)
		ra(stack_a);
	if (i == 2 || i == 1)
		sa(stack_a);
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

static void	sort_4_5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->i == 1)
			break ;
		i++;
		tmp = tmp->n;
	}
	if (i == 0)
		rra(stack_a);
	if (i == 1)
		ra(stack_a);
	if (i == 2 || i == 1)
		sa(stack_a);
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->i == 0)
			break ;
		i++;
		tmp = tmp->n;
	}
	if (i == 0 || i == 1)
		rra(stack_a);
	if (i == 1)
		rra(stack_a);
	if (i == 2)
		ra(stack_a);
	if (i == 2 || i == 3)
		sa(stack_a);
	pb(stack_a, stack_b);
	sort_4_5(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	ft_radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head;
	int		i;
	int		j;
	int		size;

	i = 0;
	size = ftt_lstsize(*stack_a);
	while (!issorted(stack_a))
	{
		j = 0;
		head = *stack_a;
		while (j < size && head && !issorted(stack_a))
		{
			if ((ftt_lstlast(*stack_a)->i >> i) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (!isempty(stack_b))
			pa(stack_a, stack_b);
		i++;
	}
}
