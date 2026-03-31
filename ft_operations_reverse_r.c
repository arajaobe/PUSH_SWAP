
#include "ft_push_swap.h"

static int	reverse_rotate(t_stack	**head)
{
	int	current;
	int previous;
	t_stack	*p;

	if (!*head)
		return (0);
	p = *head;
	previous = p->content;
	while (p->next)
	{
		current = p->next->content;
		p->next->content = previous;
		previous = current;
		p = p->next;
	}
	(*head)->content = previous;
	return (1);
}


int	rra(t_stack **a, int *op_counters)
{
	int x;

	x = reverse_rotate(a);
	ft_printf(1, "rra\n");
	op_counters[OP_RRA]++;
	return (x);
}

int	rrb(t_stack **b, int *op_counters)
{
	int	x;
	x = reverse_rotate(b);
	ft_printf(1, "rrb\n");
	op_counters[OP_RRB]++;
	return (x);
}

int	rrr(t_stack **a, t_stack **b, int *op_counters)
{
	int	x;
	int	y;

	x = reverse_rotate(a);
	y = reverse_rotate(b);
	ft_printf(1, "rrr\n");
	op_counters[OP_RRR]++;
	return (x + y);
}
