/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samrazaf <samrazaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 17:33:38 by samrazaf          #+#    #+#             */
/*   Updated: 2026/03/30 17:36:40 by samrazaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"


int	check_len_sort(t_parse_result *stack, int len)
{
	int count;

	count = 0;
	if (is_sorted(stack->stack_a))
	{
		count = 1;
		return (count);
	}
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
	if (len <= 15)
	{
		count = 1;
		return (count);
	}
	return (count);
}

int	handle_len_sort(t_parse_result *stack, int *op_counters, int len)
{
	int count;

	count = 0;
	if (is_sorted(stack->stack_a))
		count = 0;
	else if (len == 2)
	{
		count = tiny_sort(stack, op_counters);
	}
	else if (len == 3)
	{
		count = mini_sort(stack, op_counters);
	}
	else if (len <= 15)
	{
		count = short_sort(stack, op_counters);
	}
	return (count);
}
int	error_arg(int argc)
{
	if (argc <= 1)
	{
		ft_printf(2, "Error\n");
		exit(1);
	}
	return (0);
}

static int	push_findmax_calculate(t_parse_result *stack, int index, int len, int *op_counters)
{
	int count;

	count  = 0;
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
	int len;
	int	count;
	int i;

	count = 0;
	len = count_nodes(stack->stack_b);
	while (stack->stack_b)
	{
		i = search_content(&stack->stack_b,  find_max(&stack->stack_b, len));
		count += push_findmax_calculate(stack, i, len, op_counters);
		count += pa(&stack->stack_a, &stack->stack_b, op_counters);
		len = count_nodes(stack->stack_b);
	}
	return (count);
}
