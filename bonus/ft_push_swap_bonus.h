/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samrazaf <samrazaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:58:04 by arajaobe          #+#    #+#             */
/*   Updated: 2026/04/08 19:43:01 by samrazaf         ###   ########.fr       */
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

int				ft_isdigit(int c);
int				ft_atoi(const char *nptr);
long			ft_atol(const char *str);
int				is_valid_digit(char *s);
int				ft_isnumber(char *s);
void			ft_lstclear(t_stack **lst);
void			ft_free_split(char **split);
void			append_node(t_stack **head, t_stack **current,
					t_stack *new_node);
void			parse_tab(char **tab, t_stack **head, t_stack **current);
void			handle_arg(char *arg, t_stack **head, t_stack **current);
int				ft_strcmp(const char *s1, const char *s2);
int				is_flag(char *arg);
void			error_check(t_parse_result *stack);
int				duplicate(t_stack **a);
t_parse_result	list_arg_fillers_new(int argc, char **argv);
void			execute_function(t_parse_result *stack, char *str);
double			disorder_metrics(t_stack *head);
char			**ft_split(char const *s, char c);
t_stack			*ft_lstnew(int content);
int				count_nodes(t_stack *head);
int				find_content(t_stack *head, int pos);
int				find_index(t_stack *head, int pos);
int				search_content(t_stack **head, int find);
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

#endif
