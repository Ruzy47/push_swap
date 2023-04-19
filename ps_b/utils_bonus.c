/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:28:00 by rugrigor          #+#    #+#             */
/*   Updated: 2023/04/19 16:22:02 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	lenn(char **av, int i)
{
	int	len;

	len = 0;
	if (!av)
		return (0);
	while (av[i])
	{
		len++;
		i++;
	}
	return (len);
}

char	**number(char **v)
{
	char	**num;
	int		n;
	int		i;
	int		len;

	n = 0;
	i = 0;
	len = lenn(v, 0);
	num = (char **)malloc(sizeof(char *) * (len + 1));
	if (!num)
		return (0);
	while (v[i] != 0)
			num[n++] = v[i++];
	num[n] = NULL;
	return (num);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	listfree(t_stack *x)
{
	t_stack	*ls_free;

	while (x)
	{
		ls_free = x;
		x = x->next;
		free(ls_free);
	}
}
