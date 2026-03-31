/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaobe <arajaobe@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:58:04 by arajaobe          #+#    #+#             */
/*   Updated: 2026/03/25 14:43:11 by arajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_stack
{
	int	content;
	int	index;
	struct s_stack	*next;
}	t_stack;

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR
}t_op;

typedef enum e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}t_strategy;

typedef struct	s_parse_result
{
	t_stack *stack_a;
	t_stack *stack_b;
	int		bench_mode;
	t_strategy strategy;
}t_parse_result;

t_parse_result	list_arg_fillers_new(int argc, char **argv);
t_stack			*ft_lstnew(int	content);
t_stack			*find_link(t_stack *head, int pos);
int				pb(t_stack **a, t_stack **b, int *op_counters);
int				pa(t_stack **a, t_stack **b, int *op_counters);
int				sa(t_stack **a, int *op_counters);
int				sb(t_stack **b, int *op_counters);
int				ss(t_stack **a, t_stack **b, int *op_counters);
int				ra(t_stack **a, int *op_counters);
int				rb(t_stack **b, int *op_counters);
int				rr(t_stack **a, t_stack **b, int *op_counters);
int				rra(t_stack **a, int *op_counters);
int				rrb(t_stack **b, int *op_counters);
int				rrr(t_stack **a, t_stack **b, int *op_counters);
int				count_nodes(t_stack *head);
int				find_content(t_stack *head, int pos);
double			disorder_metrics(t_stack *head);
void			insertsort(int	*tab, int size);
int				search_content(t_stack **head, int find);
void			fill_index(t_stack **head, int	*array);
int				ft_atoi(const char *nptr);
long 			ft_atol(const char *str);
void			*ft_memset(void *s, int c, size_t n);
void			print_index(t_stack *head);
void			array_sort(t_stack **a, int *array);
int				intchr(int to_find, int *range, size_t size);
int				int_sqrt(int n);
int				find_max(t_stack **head, int len);
int 			find_min (t_stack **head, int len);
int				check_pos_from_edge(t_stack **head, int check);
int				push_findmax(t_parse_result *stack, int *op_counters);
int				medium_sort(t_parse_result *stack, int *op_counters);
int				improved_simple_sort(t_parse_result *stack, int *op_counters);
void 			print_bench( t_strategy strat, int *op_counters, double disorder_metrics, int total_ops);
int				complex_sort(t_parse_result *stack, int *op_counters);
int				find_index(t_stack *head, int pos);
int				 bit_count(int max_index);
int				find_max_bits(t_stack **head, int len);
char			**ft_split(char	const *s, char c);
char			*ft_substr(const char *s, unsigned int start, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_isdigit(int c);
int				duplicate(t_stack **a);
void			ft_lstclear(t_stack **lst);
int				run_strategy(t_strategy strat, t_parse_result *stack, int *op_counters);
int				ft_isnumber(char *s);
void 			ft_free_split(char **split);
int				is_valid_digit(char *s);
int				adaptive_sort(t_parse_result *stack, int *op_operation, double disorder);
int				tiny_sort(t_parse_result *stack, int *op_counters);
int				is_sorted(t_stack *stack);
int				mini_sort(t_parse_result *a, int *op_counters);
int				short_sort(t_parse_result *ptr, int *op_counters);
int				check_len_sort(t_parse_result *stack, int len);
int				handle_len_sort(t_parse_result *stack, int *op_counters, int len);
int				error_arg(int argc);
void			handle_arg(char *arg, t_stack **head, t_stack **current);
int				is_flag(char *arg);
void			handle_flag(char *arg, t_parse_result *result);

#endif
