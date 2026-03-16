/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaobe <arajaobe@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:58:04 by arajaobe          #+#    #+#             */
/*   Updated: 2026/03/16 13:37:50 by arajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_stack
{
	int	content;
	int	index;
	struct s_stack	*next;
}	t_stack;

void	print_num(t_stack *a, t_stack *b);
void	print_stacks(t_stack *a, t_stack *b);
t_stack	*ft_lstnew(int	content);
t_stack	*list_fillers(int stop, ...);
t_stack	*list_arg_fillers(int argc, char **argv);
t_stack	*find_link(t_stack *head, int pos);
int		pb(t_stack **a, t_stack **b);
int		pa(t_stack **a, t_stack **b);
int		sa(t_stack **a);
int		sb(t_stack **b);
int		ss(t_stack **a, t_stack **b);
int		reverse(t_stack	**head);
int		reverse_reverse(t_stack	**head);
int		ra(t_stack **a);
int		rb(t_stack **b);
int		rr(t_stack **a, t_stack **b);
int		rra(t_stack **a);
int		rrb(t_stack **b);
int		rrr(t_stack **a, t_stack **b);
int		count_nodes(t_stack *head);
int		find_content(t_stack *head, int pos);
float	disorder_metrics(t_stack *head);
void	insertsort(int	*tab, int size);
int		search_content(t_stack **head, int find);
void	fill_index(t_stack **head, int	*array);
int		ft_atoi(const char *nptr);
void	print_index(t_stack *head);
void	array_sort(t_stack **a, int *array);
int		intchr(int to_find, int *range, int size);
int		int_sqrt(int n);
int		find_max(t_stack **head, int len);
int 	find_min (t_stack **head, int len);
int		check_pos_from_edge(t_stack **head, int check);
int		calculate_medium(t_stack **a, int pos, int index, int len);
int		rotate_medium(t_stack **a, t_stack **b, int *array, int size);
int		push_findmax_calculate(t_stack **b, int index, int len);
int		push_findmax(t_stack **a, t_stack **b);
int		temporary_medium(int *array, int size, int index, int *temp);
int		medium_core(t_stack **a, t_stack **b, int *array);
int		medium_sort(t_stack **a, t_stack **b);
int		simple_sort(t_stack **a, t_stack **b);
int		improved_simple_sort(t_stack **a, t_stack **b);


#endif
