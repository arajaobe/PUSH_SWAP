/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaobe <arajaobe@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:37:53 by arajaobe          #+#    #+#             */
/*   Updated: 2026/03/23 16:48:15 by arajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_push_swap.h"


int	calculate_medium(t_stack **a, int index, int len, int *op_counters)
{
	int count;
	int pos;

	pos = index;
	count  = 0;
	if (index> (len / 2) + 1)
	{
		while (pos != len + 1)
		{
			count += rra(a, op_counters);
			pos++;
		}
	}
	else
	{
		while (pos != 1)
		{
			count += ra(a, op_counters);
			pos--;
		}
	}
	return (count);
}

int	rotate_medium(t_stack **a, t_stack **b, int *array, size_t size, int *op_counters)
{
	int	i;
	int	len;
	int pos;
	int count;

	len = count_nodes(*a);
	size = sizeof(array);
	count = 0;
	i = 1;
	while (i <= len)
	{
		pos = i;
		if (intchr(find_content(*a, i), array, size))
		{
			count += calculate_medium(a, i, len, op_counters);
			count += pb(a, b, op_counters);
			i = 0;
		}
		len = count_nodes(*a);
		i++;
	}
	return (count);
}


int	push_findmax_calculate(t_stack **b, int index, int len, int *op_counters)
{
	int count;

	count  = 0;
	if (index > (len / 2) + 1)
	{
		while (index != len + 1)
		{
			count += rrb(b, op_counters);
			index++;
		}
	}
	else
	{
		while (index != 1)
		{
			count += rb(b, op_counters);
			index--;
		}
	}
	return (count);
}

int	push_findmax(t_stack **a, t_stack **b, int *op_counters)
{
	int len;
	int	count;
	int i;

	count = 0;
	len = count_nodes(*b);
	while (*b)
	{
		i = search_content(b,  find_max(b, len));
		count += push_findmax_calculate(b, i, len, op_counters);
		count += pa(a,b, op_counters);
		len = count_nodes(*b);
	}
	return (count);
}


int	temporary_medium(int *array, int size, int index, int *temp)
{
	int j;

	j = 0;
	while (j < size)
	{
		temp[j] = array[index];
		index++;
		j++;
	}
	return (index);
}
