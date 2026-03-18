/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaobe <arajaobe@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:58:31 by arajaobe          #+#    #+#             */
/*   Updated: 2026/03/16 17:04:53 by arajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
	printf("sa\n");
	op_counters[OP_SA]++;
	return (x);
}

int	sb(t_stack **b, int *op_counters)
{
	int x;

	x = swap(b);
	printf("sb\n");
	op_counters[OP_SB]++;
	return (x);

}

int	ss(t_stack **a, t_stack **b, int *op_counters)
{
	int x;
	int y;
	x = swap(a);
	y = swap(b);
	printf("ss\n");
	op_counters[OP_SS]++;
	return (x + y);
}

int	pb(t_stack **a, t_stack **b, int *op_counters)
{
	t_stack	*temp;

	if (!a)
		return (0);
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	printf("pb\n");
	op_counters[OP_PB]++;
	return (1);
}

int	pa(t_stack **a, t_stack **b, int *op_counters)
{
	t_stack	*temp;

	if (!b)
		return (0);
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	printf("pa\n");
	op_counters[OP_PA]++;
	return (1);
}

int	reverse_rotate(t_stack	**head)
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

int	rotate(t_stack	**head)
{
	int	current;
	int after;
	t_stack	*p;

	if (!*head)
		return (0);
	p = *head;
	current = p->content;
	while (p->next)
	{
		after = p->next->content;
		p->content = after;
		p = p->next;
	}
	p->content = current;
	return (1);
}

void	rotate_index(t_stack	**head)
{
	int	current;
	int after;
	t_stack	*p;

	if (!*head)
		return ;
	p = *head;
	current = p->index;
	while (p->next)
	{
		after = p->next->index;
		p->index = after;
		p = p->next;
	}
	p->index = current;
}


int	ra(t_stack **a, int *op_counters)
{
	int	x;

	x = rotate(a);
	rotate_index(a);
	printf("ra\n");
	op_counters[OP_RA]++;
	return (x);
}

int	rb(t_stack **b, int *op_counters)
{
	int	x;

	x = rotate(b);
	rotate_index(b);
	printf("rb\n");
	op_counters[OP_RB]++;
	return (x);
}

int	rr(t_stack **a, t_stack **b, int *op_counters)
{
	int	x;
	int	y;

	x = rotate(a);
	y = rotate(b);
	printf("rr\n");
	op_counters[OP_RR]++;
	return (x + y);
}

int	rra(t_stack **a, int *op_counters)
{
	int x;

	x = reverse_rotate(a);
	printf("rra\n");
	op_counters[OP_RRA]++;
	return (x);
}

int	rrb(t_stack **b, int *op_counters)
{
	int	x;
	x = reverse_rotate(b);
	printf("rrb\n");
	op_counters[OP_RRB]++;
	return (x);
}

int	rrr(t_stack **a, t_stack **b, int *op_counters)
{
	int	x;
	int	y;

	x = reverse_rotate(a);
	y = reverse_rotate(b);
	printf("rrr\n");
	op_counters[OP_RRR]++;
	return (x + y);
}
