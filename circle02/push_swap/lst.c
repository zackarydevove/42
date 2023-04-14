/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:16:48 by zdevove           #+#    #+#             */
/*   Updated: 2022/12/26 12:09:15 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ftt_lstnew(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->number = value;
	new->i = -1;
	new->n = NULL;
	return (new);
}

t_stack	*ftt_lstlast(t_stack *lst)
{
	while (lst->n)
	{
		if (!lst->n)
			return (lst);
		lst = lst->n;
	}
	return (lst);
}

int	ftt_lstsize(t_stack *lst)
{
	int		len;
	t_stack	*tmp;

	len = 0;
	tmp = lst;
	while (tmp != 0)
	{
		tmp = tmp->n;
		len++;
	}
	return (len);
}

void	ftt_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (new)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		last = ftt_lstlast(*lst);
		last->n = new;
	}
}

void	ftt_lstclear(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*lst;

	lst = *stack;
	while (lst != 0)
	{
		tmp = lst->n;
		free(lst);
		lst = tmp;
	}
}
