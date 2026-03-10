/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_decreasing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samrazaf <samrazaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:33:55 by samrazaf          #+#    #+#             */
/*   Updated: 2026/03/08 17:20:53 by samrazaf         ###   ########.fr       */
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
