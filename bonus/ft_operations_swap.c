/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samrazaf <samrazaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 17:01:04 by samrazaf          #+#    #+#             */
/*   Updated: 2026/04/08 19:13:05 by samrazaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

static int	swap(t_stack **head)
{
	int	temp;

	if (!*head || !(*head)->next)
		return (0);
	temp = (*head)->content;
	(*head)->content = (*head)->next->content;
	(*head)->next->content = temp;
	return (1);
}

int	sa(t_stack **a)
{
	int	x;

	x = swap(a);
	return (x);
}

int	sb(t_stack **b)
{
	int	x;

	x = swap(b);
	return (x);
}

int	ss(t_stack **a, t_stack **b)
{
	int	x;
	int	y;

	x = swap(a);
	y = swap(b);
	return (x + y);
}
