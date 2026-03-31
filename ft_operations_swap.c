
#include "ft_push_swap.h"

static int	swap(t_stack **head)
{
	int temp;

	if (!*head || !(*head)->next)
		return (0);
	temp = (*head)->content;
	(*head)->content = (*head)->next->content;
	(*head)->next->content = temp;
	return (1);
}
int	sa(t_stack **a,  int *op_counters)
{
	int x;

	x = swap(a);
	ft_printf(1, "sa\n");
	op_counters[OP_SA]++;
	return (x);
}

int	sb(t_stack **b, int *op_counters)
{
	int x;

	x = swap(b);
	ft_printf(1, "sb\n");
	op_counters[OP_SB]++;
	return (x);

}

int	ss(t_stack **a, t_stack **b, int *op_counters)
{
	int x;
	int y;
	x = swap(a);
	y = swap(b);
	ft_printf(1, "ss\n");
	op_counters[OP_SS]++;
	return (x + y);
}
