/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:28:23 by rugrigor          #+#    #+#             */
/*   Updated: 2023/04/07 20:18:36 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

int		sort_av(char **av);
int		errors(char **av);
char	**pars(char **v, int i);
int		lenn(char **av, int i);
char	**plit(char **av, int i);
void	fly(t_stack **a, t_stack **b, int i);
void	litfly(t_stack **a, t_stack **b, int i);
char	**number(char **v);
void	listfree(t_stack **x);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack *a, t_stack *b);

#endif
