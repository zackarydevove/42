/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:13:41 by zdevove           #+#    #+#             */
/*   Updated: 2022/12/26 11:36:06 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Last node of stack_a become first
void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putendl_fd("ra", 1);
}

// Last node of stack_b become first
void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putendl_fd("rb", 1);
}

// Last node of both become first
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
}

// First node of stack_a become first
void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_putendl_fd("rra", 1);
}

// First node of stack_b become first
void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_putendl_fd("rrb", 1);
}
