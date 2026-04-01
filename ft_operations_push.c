/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samrazaf <samrazaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:58:31 by arajaobe          #+#    #+#             */
/*   Updated: 2026/04/01 17:10:01 by samrazaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	pb(t_stack **a, t_stack **b, int *op_counters)
{
	t_stack	*temp;

	if (!a)
		return (0);
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	ft_printf(1, "pb\n");
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
	ft_printf(1, "pa\n");
	op_counters[OP_PA]++;
	return (1);
}
