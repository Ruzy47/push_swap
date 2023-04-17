/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:28:00 by rugrigor          #+#    #+#             */
/*   Updated: 2023/03/29 13:28:03 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

char	**number(char **v)
{
	char 	**num;
	int		n;
	int		i;
	int		len;
	
	n = 0;
	i = 0;
	len = lenn(v, 0);
	num = (char**)malloc(sizeof(char*) * (len + 1));
	if (!num)
		return (0);
	while (v[i] != 0)
			num[n++] = v[i++];
	num[n] = NULL;
	return (num);
}

int	main(int ac, char **av)
{
	int		i;
	t_stack	*a;
	t_stack	*b;
	char	**str;
	char	**num;
	char	**v;

	a = NULL;
	b = NULL;
	i = -1;
	v = plit(av, 1);
	if (ac == 1 || sort_av(v) != 0)
		return (0);
	if (errors(v) != 0)
		return (write (1, "Error\n", 6));
	str = pars(v, 0);
	num = number(v);
	while (str[++i])
		add_back(&a, new(ft_atoi(str[i]), ft_atoi(num[i])));
	if (i <= 12)
		litfly(&a, &b, i);
	else
		fly (&a, &b, i - 1);
	//  t_stack *p = a;
	//  while (p)
	//  {
	//  	 printf("%d\n", p->num);
	//  	p = p->next;
	//  }
	listfree(a);
	listfree(b);
	free(num);
//	system ("leaks push_swap");
}
