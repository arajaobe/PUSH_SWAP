/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_decreasing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samrazaf <samrazaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:33:55 by samrazaf          #+#    #+#             */
/*   Updated: 2026/03/12 12:12:33 by samrazaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	is_decreasing(t_stack **tab)
{
	t_stack	*ptr;

	if (!tab || !*tab)
		return (1);
	ptr = *tab;
	while (ptr->next)
	{
		if (ptr->content < ptr->next->content)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int	reverse_all(t_stack **a, t_stack **b)
{
	int	count;
	int	len;
	int	i;

	i = 0;
	count = 0;
	len = count_nodes(*a);
	if (is_decreasing(a))
	{
		while (i < len)
		{
			count += rra(a);
			count += pb(a, b);
			i ++;
		}
		i = 0;
		while (i < len)
		{
			count += pa(a, b);
			i ++;
		}
	}
	return (count);
}
