/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <rugrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:28:00 by rugrigor          #+#    #+#             */
/*   Updated: 2023/04/20 18:48:00 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	dif(char **av)
{
	int	i;
	int	j;
	int	n;
	int	x;

	i = 0;
	n = 1;
	while (av[i])
	{
		x = 0;
		while (av[i][x] && av[i][x] == '0')
				x++;
		while (av[n])
		{
			j = 0;
			while (av[n][j] && av[n][j] == '0')
				j++;
			if (av[i][x] == '-' && av[i][x + 1] == '0' && av[n][j] == 0)
				return (1);
			if (ft_strcmp(&av[i][x], &av[n][j]) == 0)
				return (1);
			n++;
		}
		i++;
		n = i + 1;
	}
	return (0);
}

int	errors(char **av, int i, int n)
{
	int		j;

	if (dif(av) != 0)
		return (1);
	while (av[++i])
	{
		j = 0;
		while (av[i][j] && av[i][j] == '0')
			j++;
		if (ft_strlen(&av[i][j]) > 11)
			return (1);
		n = -1;
		if (ft_atol(av[i]) > 2147483647 || ft_atol(av[i]) < -2147483648)
			return (1);
		while (av[i][++n])
		{
			if ((av[i][0] == '-' && n == 0) || (av[i][0] == '+' && n == 0))
				n++;
			if (!(av[i][n] > 47 && av[i][n] < 58))
				return (1);
		}
	}
	return (0);
}
