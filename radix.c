/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samrazaf <samrazaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:17:13 by samrazaf          #+#    #+#             */
/*   Updated: 2026/03/18 17:56:14 by samrazaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	pa_all(t_stack **a, t_stack **b)
{
	int	x;
	int	y;
	int	i;

	y = count_nodes(*b);
	i = 0;
	x = 0;
	while (i < y)
	{
		x += pa(a, b);
		i ++;
	}
	return (x);
}

int	radix(t_stack **a, t_stack **b)
{
	t_stack	*x;
	int	max;
	int	j;
	int	bit_len;
	int	i;
	int	count;

	max = find_max(a, count_nodes(*a));
	bit_len = 0;
	count = 0;
	while ((max >> bit_len) != 0)
		bit_len ++;
	i = 0;
	while (i < bit_len)
	{
		j = count_nodes(*a);
		while (j > 0)
		{
			x = *a;
			if (((x->content >> i) & 1) == 0)
				count += pb(a, b);
			else
				count += ra(a);
			j --;
		}
		count += pa_all(a, b);
		i ++;
	}
	return (count);
}

