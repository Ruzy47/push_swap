/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <rugrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:28:00 by rugrigor          #+#    #+#             */
/*   Updated: 2023/04/20 14:43:06 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*last(t_stack *lst)
{
	while (lst)
	{
		if (lst -> next)
			lst = lst -> next;
		else
			return (lst);
	}
	return (NULL);
}

t_stack	*new(int index, int num)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == 0)
		return (NULL);
	new->index = index;
	new->num = num;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	add_back(t_stack **lst, t_stack *new)
{
	t_stack	*tsl;

	tsl = *lst;
	if (!tsl || !*lst)
	{
		*lst = new;
		return ;
	}
	tsl = last(tsl);
	tsl -> next = new;
	new->prev = tsl;
}

void	fill(char **v, t_stack **a)
{
	char	**str;
	char	**num;
	int		i;

	i = -1;
	str = pars(v, 0);
	num = number(v);
	while (str[++i])
		add_back(a, new(ft_atol(str[i]), ft_atol(num[i])));
	i = -1;
	while (str && str[++i])
		free(str[i]);
	free(str);
	free(num);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**v;

	a = NULL;
	b = NULL;
	v = plit(av, 1);
	if (ac == 1 || !v[0])
		return (0);
	if (errors(v, -1, -1) != 0)
		return (write (2, "Error\n", 6));
	fill(v, &a);
	checker(&a, &b);
	listfree(a);
	return (0);
}
