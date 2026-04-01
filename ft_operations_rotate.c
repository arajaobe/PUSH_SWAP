/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samrazaf <samrazaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 17:00:59 by samrazaf          #+#    #+#             */
/*   Updated: 2026/04/01 17:12:07 by samrazaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	rotate(t_stack	**head)
{
	int		current;
	int		after;
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

static void	rotate_index(t_stack	**head)
{
	int		current;
	int		after;
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
	ft_printf(1, "ra\n");
	op_counters[OP_RA]++;
	return (x);
}

int	rb(t_stack **b, int *op_counters)
{
	int	x;

	x = rotate(b);
	rotate_index(b);
	ft_printf(1, "rb\n");
	op_counters[OP_RB]++;
	return (x);
}

int	rr(t_stack **a, t_stack **b, int *op_counters)
{
	int	x;
	int	y;

	x = rotate(a);
	y = rotate(b);
	ft_printf(1, "rr\n");
	op_counters[OP_RR]++;
	return (x + y);
}
