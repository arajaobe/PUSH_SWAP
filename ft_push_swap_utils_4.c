/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils_4.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samrazaf <samrazaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 17:01:23 by samrazaf          #+#    #+#             */
/*   Updated: 2026/04/01 17:28:49 by samrazaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	int_sqrt(int n)
{
	int	x;

	if (n == 0 || n == 1)
		return (n);
	x = n / 2;
	while (x > n / x)
	{
		x = (x + n / x) / 2;
	}
	return (x);
}

int	find_max_bits(t_stack **head, int len)
{
	int	max;
	int	i;

	max = find_index(*head, 1);
	i = 2;
	while (i <= len)
	{
		if (find_index(*head, i) > max)
			max = find_index(*head, i);
		i++;
	}
	return (max);
}

int	find_max(t_stack **head, int len)
{
	int	max;
	int	i;

	max = find_content(*head, 1);
	i = 2;
	while (i <= len)
	{
		if (find_content(*head, i) > max)
			max = find_content(*head, i);
		i++;
	}
	return (max);
}

int	find_min(t_stack **head, int len)
{
	int	min;
	int	i;

	min = find_content(*head, 1);
	i = 2;
	while (i <= len)
	{
		if (find_content(*head, i) < min)
			min = find_content(*head, i);
		i++;
	}
	return (min);
}

int	intchr(int to_find, int *range, size_t size)
{
	int		res;
	size_t	i;

	res = 0;
	i = 0;
	while (i < size)
	{
		if (to_find == range[i])
			res = 1;
		i++;
	}
	return (res);
}
