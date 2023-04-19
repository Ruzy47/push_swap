/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   litfly.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:28:00 by rugrigor          #+#    #+#             */
/*   Updated: 2023/03/29 13:28:03 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	litfly_cont(t_stack **a, t_stack **b, int i, int n)
{
	int		x;
	t_stack	*aa;

	while (i != 3)
	{
		x = 0;
		aa = *a;
		while (aa)
		{
			if (aa->index == n)
				break ;
			x++;
			aa = aa->next;
		}
		n++;
		while ((*a)->index != aa->index)
		{
			if (x < i / 2)
				ra(a);
			else
				rra(a);
		}
		pb(a, b);
		i--;
	}
}

void	litfly_cont_a(t_stack **a)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->index;
	y = (*a)->next->index;
	z = (*a)->next->next->index;
	if (x < y && x < z && y > z)
	{
		rra(a);
		sa(*a);
	}
	else if (x < y && x > z)
		rra(a);
	else if (x > y && y > z)
	{
		sa(*a);
		rra(a);
	}
	else if (x > y && x > z)
		ra(a);
	else if (x > y && x < z)
		sa(*a);
}

void	litfly(t_stack **a, t_stack **b, int i)
{
	if (i == 2)
		sa(*a);
	else if (i == 3)
		litfly_cont_a(a);
	else
	{
		litfly_cont(a, b, i, 0);
		litfly_cont_a(a);
		while (*b)
			pa(a, b);
	}
}

void	listfree(t_stack **x)
{
	t_stack	*ls_free;

	while (*x)
	{
		ls_free = (*x)->next;
		free(*x);
		*x = ls_free;
	}
}
