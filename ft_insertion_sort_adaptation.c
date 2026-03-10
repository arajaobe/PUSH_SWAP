/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_sort_adaptation.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samrazaf <samrazaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 15:51:53 by samrazaf          #+#    #+#             */
/*   Updated: 2026/03/10 18:18:40 by samrazaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_insertion(t_stack **a, t_stack **b)
{
	t_stack	*x;
	t_stack	*y;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (*a && (*a)->next != NULL)
	{
		x = *a;
		if (x->content > x->next->content)
		{
			sa(a);
			count ++;
		}
		pb(a, b);
		count ++;
		while (!is_decreasing(b))
		{
			y = *b;
			if (y->content < y->next->content)
			{
				sb(b);
				count ++;
			}
			else if (y->content > y->next->content && y->content < y->next->next->content)
			{
				while (i > 0)
				{
					rrb(b);
					i --;
					count ++;
				}
			}
			else if (y->content > y->next->content && y->next->content > y->next->next->content)
			{
				while (i > 0)
				{
					rrb(b);
					i --;
					count ++;
				}
			}
			else
			{
				rb(b);
				i ++;
				count ++;
			}
		}
	}
	return (count);
}
