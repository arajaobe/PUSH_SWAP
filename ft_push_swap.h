
#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_stack
{
	int	content;
	struct s_stack	*next;
}	t_stack;

void	 print_num(t_stack *a, t_stack *b);
void	print_stacks(t_stack *a, t_stack *b);
t_stack	*ft_lstnew(int	content);
t_stack	*list_fillers(int stop, ...);
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

#endif
