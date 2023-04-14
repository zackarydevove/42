/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:11:01 by zdevove           #+#    #+#             */
/*   Updated: 2022/12/26 11:45:17 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first 2 elements at top of stack A
void	sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_putendl_fd("sa", 1);
}

// Swap the first 2 elements at top of stack B
void	sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_putendl_fd("sb", 1);
}

// Swap a && Swap b
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
}

// Push top element of b to top a
void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_putendl_fd("pa", 1);
}

// Push top element of a to top b
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putendl_fd("pb", 1);
}
