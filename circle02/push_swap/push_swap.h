/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:18:06 by zdevove           #+#    #+#             */
/*   Updated: 2023/01/01 10:08:53 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>

// Stack Linked List struct (with sorted indexes)
typedef struct s_stack {
	int				number;
	int				i;
	struct s_stack	*n;
}		t_stack;

// List
t_stack	*ftt_lstnew(int value);
t_stack	*ftt_lstlast(t_stack *lst);
int		ftt_lstsize(t_stack *lst);
void	ftt_lstadd_back(t_stack **lst, t_stack *new);
void	ftt_lstadd_front(t_stack **lst, t_stack *new);
void	ftt_lstclear(t_stack **stack);

// Operations
void	swap(t_stack **stack);
void	push(t_stack **stack_from, t_stack **stack_to);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);

void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

// Utils
int		issorted(t_stack **stack);
int		isempty(t_stack **stack);
int		isdouble(char **av, int nb, int i);
int		isnumber(char *s);
void	ftt_free_av(char **av);
int		ismaxint(char *s);

// Radix Sort
void	ft_radix_sort(t_stack **stack_a, t_stack **stack_b);
void	sort_3(t_stack **stack_a);
void	sort_4(t_stack **stack_a, t_stack **stack_b);
void	sort_5(t_stack **stack_a, t_stack **stack_b);

// Main
int		check_av(int ac, char ***av);
t_stack	*get_next_min(t_stack **stack_a);
int		avlen(char **av, int ac);
void	put_value_in(t_stack **stack_a, char **av, int ac);
// void	ft_printlist(t_stack **stack_a);

#endif
