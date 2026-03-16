/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaobe <arajaobe@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:37:53 by arajaobe          #+#    #+#             */
/*   Updated: 2026/03/16 13:37:55 by arajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_push_swap.h"


int	calculate_medium(t_stack **a, int pos, int index, int len)
{
	int count;

	count  = 0;
	if (index> (len / 2) + 1)
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

int	rotate_medium(t_stack **a, t_stack **b, int *array, int size)
{
	int	i;
	int	len;
	int pos;
	int count;

	len = count_nodes(*a);
	count = 0;
	i = 1;
	while (i <= len)
	{
		pos = i;
		if (intchr(find_content(*a, i), array, size))
		{
			count += calculate_medium(a, pos, i, len);
			count += pb(a,b);
			i = 0;
		}
		len = count_nodes(*a);
		i++;
	}
	return (count);
}


int	push_findmax_calculate(t_stack **b, int index, int len)
{
	int count;

	count  = 0;
	if (index > (len / 2) + 1)
	{
		while (index != len + 1)
		{
			count += rrb(b);
			index++;
		}
	}
	else
	{
		while (index != 1)
		{
			count += rb(b);
			index--;
		}
	}
	return (count);
}

int	push_findmax(t_stack **a, t_stack **b)
{
	int len;
	int	count;
	int i;

	count = 0;
	len = count_nodes(*b);
	while (*b)
	{
		i = search_content(b,  find_max(b, len));
		count += push_findmax_calculate(b, i, len);
		count += pa(a,b);
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
