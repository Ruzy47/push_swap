/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:28:00 by rugrigor          #+#    #+#             */
/*   Updated: 2023/04/19 11:55:58 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	sort_list(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp && tmp->next)
	{
		if (tmp->next != NULL && (tmp->index > tmp->next->index))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	move(char *str, t_stack **a, t_stack **b)
{
	if (ft_strcmp(str, "sa\n") == 0)
		sa(*a);
	else if (ft_strcmp(str, "sb\n") == 0)
		sb(*b);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss(*a, *b);
	else if (ft_strcmp(str, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(str, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(str, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(str, "rr\n") == 0)
		rr(*a, *b);
	else if (ft_strcmp(str, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr(*a, *b);
	else
		write(2, "Error\n", 6);
}

void	checker(t_stack **a, t_stack **b)
{
	char	*str;

	str = 0;
	while (1)
	{
		str = get_next_line(0);
		if (str)
			move(str, a, b);
		else
			break ;
		free(str);
	}
	if (!*a || *b || sort_list(*a) != 0)
		write (2, "KO\n", 3);
	else
		write (2, "OK\n", 3);
}
