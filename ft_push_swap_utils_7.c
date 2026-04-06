/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils_7.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samrazaf <samrazaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 17:33:38 by samrazaf          #+#    #+#             */
/*   Updated: 2026/04/01 17:35:48 by samrazaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	check_len_sort(int len)
{
	int	count;

	count = 0;
	if (len == 2)
	{
		count = 1;
		return (count);
	}
	if (len == 3)
	{
		count = 1;
		return (count);
	}
	if (len <= 5)
	{
		count = 1;
		return (count);
	}
	return (count);
}

int	handle_len_sort(t_parse_result *stack, int *op_counters, int len)
{
	int	count;

	count = 0;
	if (len == 2)
	{
		count = tiny_sort(stack, op_counters);
	}
	else if (len == 3)
	{
		count = mini_sort(stack, op_counters);
	}
	else if (len <= 5)
	{
		count = short_sort(stack, op_counters);
	}
	return (count);
}

static int	push_findmax_calculate(t_parse_result *stack, int index,
	int len, int *op_counters)
{
	int	count;

	count = 0;
	if (index > (len / 2) + 1)
	{
		while (index != len + 1)
		{
			count += rrb(&stack->stack_b, op_counters);
			index++;
		}
	}
	else
	{
		while (index != 1)
		{
			count += rb(&stack->stack_b, op_counters);
			index--;
		}
	}
	return (count);
}

int	push_findmax(t_parse_result *stack, int *op_counters)
{
	int	len;
	int	count;
	int	i;

	count = 0;
	len = count_nodes(stack->stack_b);
	while (stack->stack_b)
	{
		i = search_content(&stack->stack_b, find_max(&stack->stack_b, len));
		count += push_findmax_calculate(stack, i, len, op_counters);
		count += pa(&stack->stack_a, &stack->stack_b, op_counters);
		len = count_nodes(stack->stack_b);
	}
	return (count);
}
