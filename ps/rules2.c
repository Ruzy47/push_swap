/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:28:00 by rugrigor          #+#    #+#             */
/*   Updated: 2023/03/29 13:28:03 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*n;
	t_stack	*t;

	if (*a && (*a)->next)
	{
		n = *a;
		t = (*a)->next;
		t->prev = NULL;
		while ((*a)->next)
			*a = (*a)->next;
		(*a)->next = n;
		n->prev = *a;
		n->next = NULL;
		*a = (*a)->next;
		*a = t;
	}
	write (2, "ra\n", 3);
}

void	rb(t_stack **b)
{
	t_stack	*n;
	t_stack	*t;

	if (*b && (*b)->next)
	{
		n = *b;
		t = (*b)->next;
		t->prev = NULL;
		while ((*b)->next)
			*b = (*b)->next;
		(*b)->next = n;
		n->prev = *b;
		n->next = NULL;
		*b = (*b)->next;
		*b = t;
	}
	write (2, "rb\n", 3);
}

void	rra(t_stack **a)
{
	t_stack	*n;
	t_stack	*t;

	if (*a && (*a)->next)
	{
		n = *a;
		while ((*a)->next)
			*a = (*a)->next;
		t = *a;
		*a = (*a)->prev;
		(*a)->next = NULL;
		*a = n;
		t->next = *a;
		t->prev = NULL;
		(*a)->prev = t;
		(*a) = t;
	}
	write (2, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	t_stack	*n;
	t_stack	*t;

	if (*b && (*b)->next)
	{
		n = *b;
		while ((*b)->next)
			*b = (*b)->next;
		t = *b;
		*b = (*b)->prev;
		(*b)->next = NULL;
		*b = n;
		t->next = *b;
		t->prev = NULL;
		(*b)->prev = t;
		(*b) = t;
	}
	write (2, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(&a);
	rrb(&b);
	write (2, "rrr\n", 4);
}
