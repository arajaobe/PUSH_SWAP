/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_three_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samrazaf <samrazaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 18:22:09 by samrazaf          #+#    #+#             */
/*   Updated: 2026/03/31 18:38:42 by samrazaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	check_func(t_stack *x)
{
	if ((x->content > x->next->content)
		&& (x->content > x->next->next->content)
		&& (x->next->content < x->next->next->content))
		return (1);
	else if ((x->content > x->next->content)
		&& (x->content > x->next->next->content)
		&& (x->next->content > x->next->next->content))
		return (2);
	else if ((x->content < x->next->content)
		&& (x->content > x->next->next->content)
		&& (x->next->content > x->next->next->content))
		return (3);
	else if ((x->content > x->next->content)
		&& (x->content < x->next->next->content)
		&& (x->next->content < x->next->next->content))
		return (4);
	else if ((x->content < x->next->content)
		&& (x->content < x->next->next->content)
		&& (x->next->content > x->next->next->content))
		return (5);
	else
		return (0);
}

int	short_func(t_parse_result *a, int *op_counters)
{
	t_stack	*x;
	int		count;
	int		i;

	count = 0;
	x = a->stack_a;
	i = check_func(x);
	if (i == 1)
		count += ra(&a->stack_a, op_counters);
	else if (i == 2)
	{
		count += sa(&a->stack_a, op_counters);
		count += rra(&a->stack_a, op_counters);
	}
	else if (i == 3)
		count += rra(&a->stack_a, op_counters);
	else if (i == 4)
		count += sa(&a->stack_a, op_counters);
	else if (i == 5)
	{
		count += rra(&a->stack_a, op_counters);
		count += sa(&a->stack_a, op_counters);
	}
	return (count);
}
