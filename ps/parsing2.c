/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:28:00 by rugrigor          #+#    #+#             */
/*   Updated: 2023/03/29 13:28:03 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
