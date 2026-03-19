/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_strategy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaobe <arajaobe@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:33:20 by arajaobe          #+#    #+#             */
/*   Updated: 2026/03/19 14:45:33 by arajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_push_swap.h"

int bit_count(int max_index)
{
	int bits = 0;

	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}
static int complexe_core(t_stack **a, t_stack **b, int *array, int bits, int *op_counters)
{
	int i;
	int j;
	int count;
	int len;

	len  = count_nodes(*a);
	count = 0;
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < len)
		{
			if ((((*a)->index >> i) & 1) == 0)
				count += pb(a, b, op_counters);
			else
				count += ra(a, op_counters);
			j++;
		}
		while (*b)
			count += pa(a, b, op_counters);
		i++;
	}
	return (count);
}


int	complex_sort(t_stack **a, t_stack **b, int *op_counters)
{
	int	len;
	int	*array;
	int count;
	int	bits;

	count = 0;
	len = count_nodes(*a);
	if (len <= 10)
	{
		count += improved_simple_sort(a, b, op_counters);
		return (count);
	}
	array = malloc(sizeof(int) * len);
	array_sort(a, array);
	fill_index(a, array);
	bits = bit_count(find_max_bits(a, len));
	count += complexe_core(a, b, array, bits, op_counters);
	free(array);
	return count;
}
