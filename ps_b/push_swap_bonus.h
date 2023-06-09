/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <rugrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:28:23 by rugrigor          #+#    #+#             */
/*   Updated: 2023/04/20 14:43:18 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strchr(char *str, int n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*strn(char *ptr);
char	*strn2(char *ptr);
char	*ft_strdup(const char *str);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

void	checker(t_stack **a, t_stack **b);
char	**number(char **v);
int		ft_strcmp(char *s1, char *s2);
int		sort_av(char **av);
int		errors(char **av, int i, int n);
char	**pars(char **v, int i);
int		lenn(char **av, int i);
char	**plit(char **av, int i);
void	listfree(t_stack *x);
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
