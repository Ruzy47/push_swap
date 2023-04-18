/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:28:00 by rugrigor          #+#    #+#             */
/*   Updated: 2023/03/29 13:28:03 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	sort_av(char **av)
{
	int	i;

	i = 0;
	while (av[i] && av[i + 1] != NULL)
	{
		if (av[i + 1] != NULL && (ft_atoi(av[i]) > ft_atoi(av[i + 1])))
			return (0);
		i++;
	}
	return (1);
}

int	dif(char **av)
{
	int	i;
	int	n;

	i = 0;
	n = 1;
	while (av[i] && av[i + 1] != NULL)
	{	
		i++;
		while (av[n] && av[n + 1] != NULL)
		{
			n++;
			if (ft_strcmp(av[i], av[n]) == 0)
				return (1);
		}
		n = i + 1;
	}
	return (0);
}

int	errors(char **av)
{
	int		i;
	int		n;

	i = -1;
	n = -1;
	if (dif(av) != 0)
		return (1);
	while (av[++i])
	{
		n = -1;
		if (ft_strlen(av[i]) > 10)
			return (1);
		if (ft_atoi(av[i]) > 2147483647 || ft_atoi(av[i]) < -2147483648)
			return (1);
		while (av[i][++n])
		{
			if (av[i][0] == '-' || av[i][0] == '+')
				n++;
			if (!(av[i][n] > 47 && av [i][n] < 58))
				return (1);
		}
	}
	return (0);
}
