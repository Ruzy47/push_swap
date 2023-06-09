/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <rugrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:28:00 by rugrigor          #+#    #+#             */
/*   Updated: 2023/04/20 14:38:32 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	**sort2(char **str, char **ptr, int n)
{
	int		i;
	char	*p;

	while (str[++n] != NULL)
	{	
		i = -1;
		while (ptr[++i] != NULL)
		{
			if ((ft_atol(str[n]) == ft_atol(ptr[i])))
			{
				p = ft_itoa(i);
				str[n] = p;
				break ;
			}
		}
	}
	return (str);
}

char	**sort(char **str, char **ptr, int i)
{
	char	*p;

	while (ptr[i] != NULL && ptr[i + 1] != NULL)
	{
		if (ft_atol(ptr[i]) > ft_atol(ptr[i + 1]))
		{
			p = ptr[i];
			ptr[i] = ptr[i + 1];
			ptr[i + 1] = p;
			i = 0;
		}
		else
			i++;
	}
	str = sort2(str, ptr, -1);
	return (str);
}

char	**join(char **f, char **v, int i, int n)
{
	int		len1;
	int		len2;
	char	**fv;

	if (!f)
		return (v);
	if (!v)
		return (f);
	len1 = lenn(f, 0);
	len2 = lenn(v, 0);
	fv = (char **)malloc(sizeof(char *) * (len1 + len2 + 1));
	fv[len1 + len2] = NULL;
	while (f[++i])
		fv[i] = f[i];
	while (v[++n])
		fv[i++] = v[n];
	free(f);
	free(v);
	return (fv);
}

char	**plit(char **av, int i)
{
	char	**f;
	char	**v;

	v = NULL;
	while (av[i])
	{
		f = v;
		v = NULL;
		v = join(f, ft_split(av[i], ' '), -1, -1);
		f = NULL;
		i++;
	}
	return (v);
}

char	**pars(char **v, int i)
{
	char	**str;
	char	**ptr;
	int		len;

	len = lenn(v, 0);
	str = (char **)malloc(sizeof(char *) * (len + 1));
	ptr = (char **)malloc(sizeof(char *) * (len + 1));
	if (!str || !ptr)
		return (NULL);
	while (v && v[i] != 0)
	{
		str[i] = v[i];
		ptr[i] = v[i];
		i++;
	}
	ptr[i] = NULL;
	str[i] = NULL;
	str = sort(str, ptr, 0);
	i = 0;
	free(ptr);
	return (str);
}
