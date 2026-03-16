/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaobe <arajaobe@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:37:58 by arajaobe          #+#    #+#             */
/*   Updated: 2026/03/16 15:01:10 by arajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_push_swap.h"

int	use_min(t_stack**a, t_stack**b, int len)
{
	int pos;
	int count;

	count  = 0;
	pos = search_content(a, find_min(a, len));
	if (pos > (len / 2) + 1)
	{
		while (pos != len + 1)
		{
			count += rra(a);
			pos++;
		}
	}
		else
	{
		while (pos != 1)
		{
			count += ra(a);
			pos--;
		}
	}
	return (count);
}

int	use_max(t_stack**a, t_stack**b, int len)
{
	int pos;
	int count;

	count  = 0;
	pos = search_content(a, find_max(a, len));
	if (pos > (len / 2) + 1)
	{
		while (pos != len + 1)
		{
			count += rra(a);
			pos++;
		}
	}
		else
	{
		while (pos != 1)
		{
			count += ra(a);
			pos--;
		}
	}
	return (count);
}



int	improved_simple_sort(t_stack **a, t_stack **b)
{
	int	dist_min;
	int	dist_max;
	int	len;
	int	count;

	count = 0;
	len = count_nodes(*a);
	while (*a)
	{
		dist_min = check_pos_from_edge(a, find_min(a, len));
		dist_max = check_pos_from_edge(a, find_max(a, len));
		if (dist_min - dist_max <= 2)
		{
			count += use_min(a, b, len);
			count += pb(a, b);
		}
		else
		{
			count += use_max(a, b, len);
			count += pb(a, b);
		}
		len = count_nodes(*a);
	}
	count += push_findmax(a, b);
	return (count);
}
