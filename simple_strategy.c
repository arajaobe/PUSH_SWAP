/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaobe <arajaobe@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:37:58 by arajaobe          #+#    #+#             */
/*   Updated: 2026/04/01 14:43:54 by arajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_push_swap.h"

static int	calculate_minmax(t_parse_result *stack, int len, int *op_counters);
static int	use_min(t_parse_result *stack, int len, int *op_counters);
static int	use_max(t_parse_result *stack, int len, int *op_counters);


int	improved_simple_sort(t_parse_result *stack, int *op_counters)
{
	int	len;
	int	count;

	count = 0;
	len = count_nodes(stack->stack_a);
	if (check_len_sort(stack, len) == 1)
	{
		count = handle_len_sort(stack, op_counters, len);
		return (count);
	}
	while (stack->stack_a)
	{
		count += calculate_minmax(stack, len, op_counters);
		len = count_nodes(stack->stack_a);
	}
	count += push_findmax(stack, op_counters);
	return (count);
}

static int	calculate_minmax(t_parse_result *stack, int len, int *op_counters)
{
	int count;
	int dist_min;
	int dist_max;

	dist_min = check_pos_from_edge(&stack->stack_a, find_min(&stack->stack_a, len));
	dist_max = check_pos_from_edge(&stack->stack_a, find_max(&stack->stack_a, len));
	count  = 0;
	if (dist_min - dist_max <= 2)
	{
		count += use_min(stack, len, op_counters);
		count += pb(&stack->stack_a, &stack->stack_b,  op_counters);
	}
	else
	{
		count += use_max(stack, len, op_counters);
		count += pb(&stack->stack_a, &stack->stack_b, op_counters);
	}
	return (count);
}

static int	use_min(t_parse_result *stack, int len, int *op_counters)
{
	int pos;
	int count;

	count  = 0;
	pos = search_content(&stack->stack_a, find_min(&stack->stack_a, len));
	if (pos > (len / 2) + 1)
	{
		while (pos != len + 1)
		{
			count += rra(&stack->stack_a, op_counters);
			pos++;
		}
	}
		else
	{
		while (pos != 1)
		{
			count += ra(&stack->stack_a, op_counters);
			pos--;
		}
	}
	return (count);
}

static int	use_max(t_parse_result *stack,  int len, int *op_counters)
{
	int pos;
	int count;

	count  = 0;
	pos = search_content(&stack->stack_a, find_max(&stack->stack_a, len));
	if (pos > (len / 2) + 1)
	{
		while (pos != len + 1)
		{
			count += rra(&stack->stack_a, op_counters);
			pos++;
		}
	}
		else
	{
		while (pos != 1)
		{
			count += ra(&stack->stack_a, op_counters);
			pos--;
		}
	}
	return (count);
}

