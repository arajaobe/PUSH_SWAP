/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samrazaf <samrazaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:58:04 by arajaobe          #+#    #+#             */
/*   Updated: 2026/03/22 16:18:27 by samrazaf         ###   ########.fr       */
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

typedef enum
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
}e_op;

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
void	strategies(float disorder, char *strategy);
void 	print_bench(int *op_counters, double disorder_metrics, int total_ops);
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
int		check_argv(int argc, char **argv);
int		medium_sort(t_stack **a, t_stack **b, int *op_counters);
int		use_fonction(t_stack **a, t_stack **b, int *op_operation, char **argv);
int		use_adaptive_fonction(t_stack **a, t_stack **b, int *op_operation, double disorder);
int		check_argv_adaptive(int position, char **argv);

#endif
