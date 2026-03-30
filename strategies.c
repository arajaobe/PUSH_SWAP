/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaobe <arajaobe@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:38:01 by arajaobe          #+#    #+#             */
/*   Updated: 2026/03/19 14:42:36 by arajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_push_swap.h"




int	medium_core(t_stack **a, t_stack **b, int *array, int *op_counters)
{
	static int	i;
	int 		count;
	int 		len;
	int			*temp;
	size_t		chunk;

	len = count_nodes(*a);
	chunk = int_sqrt(len);
	count = 0;
	while (i < len)
	{
		if (i + chunk > len)
			chunk = len - i;
		temp = malloc(sizeof(int) * chunk);
		i = temporary_medium(array, chunk, i, temp);
		count += rotate_medium(a, b, temp, chunk, op_counters);
		free(temp);
		temp = NULL;
	}
	return (count);
}

int	medium_sort(t_stack **a, t_stack **b, int *op_counters)
{
	int	len;
	int	*array;
	int count;

	count = 0;
	len = count_nodes(*a);
	if (len <= 10)
	{
		count += improved_simple_sort(a, b, op_counters);
		return (count);
	}
	array = malloc(sizeof(int) * len);
	array_sort(a, array);
	count += medium_core(a, b, array, op_counters);
	count += push_findmax(a,b, op_counters);
	free(array);
	return count;
}

int adaptive_sort(t_stack **a, t_stack **b, int *op_operation, double disorder)
{
	int		count;

	count = 0;
	if (disorder < 0.2)
	{
		count = improved_simple_sort(a, b, op_operation);
	}
	else if (disorder >= 0.2 && disorder < 0.5)
	{
		count = medium_sort(a, b, op_operation);
	}
	else
	{
		count = complex_sort(a, b, op_operation);
	}
	return (count);
}

int	simple_sort(t_stack **a, t_stack **b, int *op_counters)
{
	int count;
	int	i;
	int	len;

	count = 0;
	len = count_nodes(*a);
	while (*a)
	{
		i = search_content(a, find_min(a, len));

		if (i > (len / 2) + 1)
		{
			while (i != len + 1)
			{
				count += rra(a, op_counters);
				i++;
			}
		}
		else
		{
			while (i != 1)
			{
				count += ra(a, op_counters);
				i--;
			}
		}
		count += pb(a, b, op_counters);
		len = count_nodes(*a);
	}
	while (*b)
	{
		count += pa(a,b, op_counters);
	}

	return (count);
}
