/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:13:54 by zdevove           #+#    #+#             */
/*   Updated: 2022/12/26 12:11:43 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap two top values of stack
void	swap(t_stack **stack)
{
	t_stack	*pre_pre_tail;
	t_stack	*pre_tail;
	t_stack	*tail;

	if (ftt_lstsize(*stack) <= 1)
		ft_putstr_fd("Nothing to do, less than 1 value in stack\n", 1);
	if (ftt_lstsize(*stack) == 2)
	{
		tail = ftt_lstlast(*stack);
		tail->n = *stack;
		(*stack)->n = NULL;
		*stack = tail;
	}
	else
	{
		pre_pre_tail = *stack;
		while (pre_pre_tail->n->n->n)
			pre_pre_tail = pre_pre_tail->n;
		pre_tail = pre_pre_tail->n;
		tail = pre_tail->n;
		pre_pre_tail->n = tail;
		tail->n = pre_tail;
		pre_tail->n = 0;
	}
}

// Push last value of stack_from to stack_to
void	push(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*pre_tail;

	if (ftt_lstsize(*stack_from) == 0)
		ft_putstr_fd("Nothing to do, 0 value in stack from\n", 1);
	ftt_lstadd_back(stack_to, ftt_lstlast(*stack_from));
	if (ftt_lstsize(*stack_from) == 1)
		*stack_from = NULL;
	else
	{
		pre_tail = *stack_from;
		while (pre_tail->n->n)
			pre_tail = pre_tail->n;
		pre_tail->n = NULL;
	}
}

// Top node become Bottom node
void	rotate(t_stack **stack)
{
	t_stack	*pre_tail;
	t_stack	*tail;

	if (ftt_lstsize(*stack) <= 1)
		ft_putstr_fd("Nothing to do, less than 1 value in stack\n", 1);
	pre_tail = *stack;
	while (pre_tail->n->n)
		pre_tail = pre_tail->n;
	tail = pre_tail->n;
	pre_tail->n = NULL;
	tail->n = *stack;
	*stack = tail;
	return ;
}

// Bottom node become Top node
void	reverse_rotate(t_stack **stack)
{
	t_stack	*tail;
	t_stack	*head;

	if (ftt_lstsize(*stack) <= 1)
		ft_putstr_fd("Nothing to do, less than 1 value in stack\n", 1);
	tail = ftt_lstlast(*stack);
	head = *stack;
	*stack = head->n;
	tail->n = head;
	head->n = NULL;
	return ;
}

// Reverse rotate both
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
}
