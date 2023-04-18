/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:28:00 by rugrigor          #+#    #+#             */
/*   Updated: 2023/04/11 15:05:32 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_stack *a)
{
	int	i;
	int	n;

	if (a && a->next)
	{
		i = a->index;
		n = a->num;
		a->index = a->next->index;
		a->num = a->next->num;
		a->next->index = i;
		a->next->num = n;
	}
	write (1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	int	i;
	int	n;

	if (b && b->next)
	{
		i = b->index;
		n = b->num;
		b->index = b->next->index;
		b->num = b->next->num;
		b->next->index = i;
		b->next->num = n;
	}
	write (1, "sb\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*n;

	if (*a)
	{
		n = *a;
		*a = (*a)->next;
		if (*a)
			(*a)->prev = NULL;
		n->next = *b;
		if (*b)
			(*b)->prev = n;
		*b = n;
	}
	write (1, "pb\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*n;

	if (*b)
	{
		n = *b;
		*b = (*b)->next;
		if (*b)
			(*b)->prev = NULL;
		n->next = *a;
		if (*a)
			(*a)->prev = n;
		*a = n;
	}
	write (1, "pa\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(&a);
	rb(&b);
	write (1, "rr\n", 3);
}
