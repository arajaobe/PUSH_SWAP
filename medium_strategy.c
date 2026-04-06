/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samrazaf <samrazaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:37:53 by arajaobe          #+#    #+#             */
/*   Updated: 2026/04/01 17:53:14 by samrazaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	medium_core(t_parse_result *stack, int *array,
				int *op_counters);
static int	calculate_medium(t_parse_result *stack, int index,
				int len, int *op_counters);
static int	rotate_medium(t_parse_result *stack, int *array,
				int size, int *op_counters);
static int	temporary_medium(int *array, int size,
				int index, int *temp);

int	medium_sort(t_parse_result *stack, t_strategy strategy, int *op_counters)
{
	int	len;
	int	*array;
	int	count;

	count = 0;
	len = count_nodes(stack->stack_a);
	if (is_sorted(stack->stack_a))
		return (count);
	if (strategy == STRAT_ADAPTIVE)
	{
		if (check_len_sort(len) == 1)
		{
			count = handle_len_sort(stack, op_counters, len);
			return (count);
		}
	}
	array = malloc(sizeof(int) * len);
	array_sort(&stack->stack_a, array);
	count += medium_core(stack, array, op_counters);
	count += push_findmax(stack, op_counters);
	free(array);
	return (count);
}

static int	medium_core(t_parse_result *stack, int *array,
				int *op_counters)
{
	static int	i;
	int			count;
	int			len;
	int			*temp;
	int			chunk;

	len = count_nodes(stack->stack_a);
	chunk = int_sqrt(len);
	count = 0;
	while (i < len)
	{
		if (i + chunk > len)
			chunk = len - i;
		temp = malloc(sizeof(int) * chunk);
		i = temporary_medium(array, chunk, i, temp);
		count += rotate_medium(stack, temp, chunk, op_counters);
		free(temp);
		temp = NULL;
	}
	return (count);
}

static int	calculate_medium(t_parse_result *stack, int index,
				int len, int *op_counters)
{
	int	count;
	int	pos;

	pos = index;
	count = 0;
	if (index > (len / 2) + 1)
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

static int	rotate_medium(t_parse_result *stack, int *array,
				int size, int *op_counters)
{
	int	i;
	int	len;
	int	count;

	len = count_nodes(stack->stack_a);
	count = 0;
	i = 1;
	while (i <= len)
	{
		if (intchr(find_content(stack->stack_a, i), array, size))
		{
			count += calculate_medium(stack, i, len, op_counters);
			count += pb(&stack->stack_a, &stack->stack_b, op_counters);
			i = 0;
		}
		len = count_nodes(stack->stack_a);
		i++;
	}
	return (count);
}

static int	temporary_medium(int *array, int size, int index, int *temp)
{
	int	j;

	j = 0;
	while (j < size)
	{
		temp[j] = array[index];
		index++;
		j++;
	}
	return (index);
}
