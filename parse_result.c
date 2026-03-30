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

// main
	t_parse_result a;
	a.stack_b = NULL;
	a = list_arg_fillers_new(argc, argv);
	x = simple_sort(&a, op_counters);
	print_stacks(a.stack_a, a.stack_b);




int	simple_sort(t_parse_result *ptr, int *op_counters)
{
	int count;
	int	i;
	int	len;

	count = 0;
	len = count_nodes(ptr->stack_a);
	while (ptr->stack_a)
	{
		i = search_content(&ptr->stack_a, find_min(&ptr->stack_a, len));

		if (i > (len / 2) + 1)
		{
			while (i != len + 1)
			{
				count += rra(&ptr->stack_a, op_counters);
				i++;
			}
		}
		else
		{
			while (i != 1)
			{
				count += ra(&ptr->stack_a, op_counters);
				i--;
			}
		}
		count += pb(&ptr->stack_a, &ptr->stack_b, op_counters);
		len = count_nodes(ptr->stack_a);
	}
	while (ptr->stack_b)
	{
		count += pa(&ptr->stack_a, &ptr->stack_b, op_counters);
	}

	return (count);
}
