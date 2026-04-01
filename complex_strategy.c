/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_strategy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samrazaf <samrazaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:33:20 by arajaobe          #+#    #+#             */
/*   Updated: 2026/04/01 17:09:27 by samrazaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	complexe_core(t_parse_result *stack, int bits, int *op_counters)
{
	int	i;
	int	j;
	int	count;
	int	len;

	len = count_nodes(stack->stack_a);
	count = 0;
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < len)
		{
			if (((stack->stack_a->index >> i) & 1) == 0)
				count += pb(&stack->stack_a, &stack->stack_b, op_counters);
			else
				count += ra(&stack->stack_a, op_counters);
			j++;
		}
		while (stack->stack_b)
			count += pa(&stack->stack_a, &stack->stack_b, op_counters);
		i++;
	}
	return (count);
}

int	complex_sort(t_parse_result *stack, int *op_counters)
{
	int	len;
	int	*array;
	int	count;
	int	bits;

	count = 0;
	len = count_nodes(stack->stack_a);
	if (check_len_sort(stack, len) == 1)
	{
		count = handle_len_sort(stack, op_counters, len);
		return (count);
	}
	array = malloc(sizeof(int) * len);
	array_sort(&stack->stack_a, array);
	fill_index(&stack->stack_a, array);
	bits = bit_count(find_max_bits(&stack->stack_a, len));
	count += complexe_core(stack, bits, op_counters);
	free(array);
	return (count);
}
