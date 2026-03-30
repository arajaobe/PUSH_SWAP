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
# include <stdio.h>
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
	int		bench_mode;
	t_strategy strategy;
}t_parse_result;

void	print_num(t_stack *a, t_stack *b);
void	print_stacks(t_stack *a, t_stack *b);
t_stack	*ft_lstnew(int	content);
t_stack	*list_fillers(int stop, ...);
t_stack	*list_arg_fillers(int argc, char **argv);
t_stack	*find_link(t_stack *head, int pos);
int		pb(t_stack **a, t_stack **b, int *op_counters);
int		pa(t_stack **a, t_stack **b, int *op_counters);
int		sa(t_stack **a, int *op_counters);
int		sb(t_stack **b, int *op_counters);
int		ss(t_stack **a, t_stack **b, int *op_counters);
int		rotate(t_stack	**head);
int		reverse_rotate(t_stack	**head);
int		ra(t_stack **a, int *op_counters);
int		rb(t_stack **b, int *op_counters);
int		rr(t_stack **a, t_stack **b, int *op_counters);
int		rra(t_stack **a, int *op_counters);
int		rrb(t_stack **b, int *op_counters);
int		rrr(t_stack **a, t_stack **b, int *op_counters);
int		count_nodes(t_stack *head);
int		find_content(t_stack *head, int pos);
double	disorder_metrics(t_stack *head);
void	insertsort(int	*tab, int size);
int		search_content(t_stack **head, int find);
void	fill_index(t_stack **head, int	*array);
int		ft_atoi(const char *nptr);
long 	ft_atol(const char *str);
void	*ft_memset(void *s, int c, size_t n);
void	print_index(t_stack *head);
void	array_sort(t_stack **a, int *array);
int		intchr(int to_find, int *range, size_t size);
int		int_sqrt(int n);
int		find_max(t_stack **head, int len);
int 	find_min (t_stack **head, int len);
int		check_pos_from_edge(t_stack **head, int check);
int		calculate_medium(t_stack **a, int index, int len, int *op_counters);
int		rotate_medium(t_stack **a, t_stack **b, int *array, size_t size, int *op_counters);
int		push_findmax_calculate(t_stack **b, int index, int len, int *op_counters);
int		push_findmax(t_stack **a, t_stack **b, int *op_counters);
int		temporary_medium(int *array, int size, int index, int *temp);
int		medium_core(t_stack **a, t_stack **b, int *array, int *op_counters);
int		medium_sort(t_stack **a, t_stack **b, int *op_counters);
int		simple_sort(t_stack **a, t_stack **b, int *op_counters);
int		improved_simple_sort(t_stack **a, t_stack **b, int *op_counters);
void	strategy_bench(t_strategy strat_bench, double disorder);
void 	print_bench( t_strategy strat, int *op_counters, double disorder_metrics, int total_ops);
int		complex_sort(t_stack **a, t_stack **b, int *op_counters);
void	rotate_index(t_stack	**head);
int		find_index(t_stack *head, int pos);
int 	find_max_bits(t_stack **head, int len);
char	**ft_split(char	const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isdigit(int c);
int		check_flags(char *str);
int		check_flags_position(int argc, char **argv);
int 	checks_flags_position_double(int argc, char **argv);
int		check_argv(int argc, char **argv);
int		use_fonction(t_stack **a, t_stack **b, int *op_operation, char **argv);
int		check_argv_adaptive(int position, char **argv);
int		duplicate(t_stack **a);
void	ft_lstclear(t_stack **lst);
int		check_bench(int position, char **argv);
int		check_flags_bench(char *str);
int 	checks_flags_position_double(int argc, char **argv);
int		check_argv_double(int argc, char **argv);
t_stack	*list_arg_fillers_double(int argc, char **argv);
t_parse_result	list_arg_fillers_new(int argc, char **argv);
int		 run_strategy(t_strategy strat, t_stack **a, t_stack **b, int *op_counters);
int		ft_isnumber(char *s);
void 	ft_free_split(char **split);
int		is_valid_digit(char *s);
int 	adaptive_sort(t_stack **a, t_stack **b, int *op_operation, double disorder);


#endif
