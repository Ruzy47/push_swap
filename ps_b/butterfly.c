/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:28:00 by rugrigor          #+#    #+#             */
/*   Updated: 2023/03/29 13:28:03 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	write (1, "ss\n", 3);
}

void	fly_cont(t_stack **b, int i)
{
	int	x;
	t_stack	*bb;

	bb = *b;
	x = 0;
	while (bb)
	{
		x++;
		if (bb->index == i)
			break;
		bb = bb->next;
	}
	if (x < i / 2)
			rb(b);
	else
			rrb(b);
}

void	fly_back(t_stack **a, t_stack **b, int i)
{
	while (*b)
	{
		if ((*b)->index == i)
		{
			pa(a, b);
			i--;
		}
		else
			fly_cont(b, i);
	}
}

int	num(int i)
{
	int	n;
	int	l;
	int	x;

	l = 1;
	n = 2;
	x = 2;
	while (1)
	{
		if (n * n <= i && ((n + 1) * (n + 1)) >= i)
			break;
		else
			n++;
	}
	while (1)
	{
		if (x <= i && x * 2 >= i)
			break;
		x = x * 2;
		l++;
	}
	return (n + l);
}

void	fly(t_stack **a, t_stack **b, int i)
{
	int	count;
	int	n;

	n = num(i);
	count = 0;
	while(*a)
	{
		if ((*a)->index <= count)
		{
			pb(a, b);
			count++;
		}
		else if ((*a)->index <= count + n)
		{
			pb(a, b);
			rb(b);
			count++;
		}
		else
			ra(a);
	}
	fly_back(a, b, i);
}