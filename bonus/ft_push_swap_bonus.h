/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samrazaf <samrazaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:58:04 by arajaobe          #+#    #+#             */
/*   Updated: 2026/04/07 19:17:27 by samrazaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_BONUS_H
# define FT_PUSH_SWAP_BONUS_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}					t_stack;

typedef struct s_parse_result
{
	t_stack		*stack_a;
	t_stack		*stack_b;
}	t_parse_result;

t_parse_result	list_arg_fillers_new(int argc, char **argv);
t_stack			*ft_lstnew(int content);
size_t			ft_strlen(const char *s);
int				pb(t_stack **a, t_stack **b);
int				pa(t_stack **a, t_stack **b);
int				sa(t_stack **a);
int				sb(t_stack **b);
int				ss(t_stack **a, t_stack **b);
int				ra(t_stack **a);
int				rb(t_stack **b);
int				rr(t_stack **a, t_stack **b);
int				rra(t_stack **a);
int				rrb(t_stack **b);
int				rrr(t_stack **a, t_stack **b);
int				count_nodes(t_stack *head);
int				find_content(t_stack *head, int pos);
int				search_content(t_stack **head, int find);
int				find_index(t_stack *head, int pos);
char			**ft_split(char const *s, char c);
char			*ft_substr(const char *s, unsigned int start, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
void			handle_arg(char *arg, t_stack **head, t_stack **current);
int				is_flag(char *arg);
void			ft_lstclear(t_stack **lst);


#endif
