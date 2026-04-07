/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_reverse_r.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samrazaf <samrazaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 17:00:51 by samrazaf          #+#    #+#             */
/*   Updated: 2026/04/07 19:00:16 by samrazaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

static int	reverse_rotate(t_stack	**head)
{
	int		current;
	int		previous;
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

int	rra(t_stack **a)
{
	int	x;

	x = reverse_rotate(a);
	ft_printf(1, "rra\n");
	return (x);
}

int	rrb(t_stack **b)
{
	int	x;

	x = reverse_rotate(b);
	ft_printf(1, "rrb\n");
	return (x);
}

int	rrr(t_stack **a, t_stack **b)
{
	int	x;
	int	y;

	x = reverse_rotate(a);
	y = reverse_rotate(b);
	ft_printf(1, "rrr\n");
	return (x + y);
}
