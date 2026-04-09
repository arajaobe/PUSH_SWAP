/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samrazaf <samrazaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 18:58:12 by samrazaf          #+#    #+#             */
/*   Updated: 2026/04/09 15:03:47 by samrazaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

int	check_error(char *str)
{
	if (ft_strcmp("pa\n", str) == 0)
		return (1);
	else if (ft_strcmp("sa\n", str) == 0)
		return (1);
	else if (ft_strcmp("ra\n", str) == 0)
		return (1);
	else if (ft_strcmp("rra\n", str) == 0)
		return (1);
	else if (ft_strcmp("pb\n", str) == 0)
		return (1);
	else if (ft_strcmp("sb\n", str) == 0)
		return (1);
	else if (ft_strcmp("rb\n", str) == 0)
		return (1);
	else if (ft_strcmp("rrb\n", str) == 0)
		return (1);
	else if (ft_strcmp("rrr\n", str) == 0)
		return (1);
	else if (ft_strcmp("ss\n", str) == 0)
		return (1);
	else
	{
		ft_printf(2, "Error");
		return (0);
	}
}

void	execute_function(t_parse_result *stack, char *str)
{
	if (ft_strcmp("pa\n", str) == 0)
		pa(&stack->stack_a, &stack->stack_b);
	if (ft_strcmp("sa\n", str) == 0)
		sa(&stack->stack_a);
	if (ft_strcmp("ra\n", str) == 0)
		ra(&stack->stack_a);
	if (ft_strcmp("rra\n", str) == 0)
		rra(&stack->stack_a);
	if (ft_strcmp("pb\n", str) == 0)
		pb(&stack->stack_a, &stack->stack_b);
	if (ft_strcmp("sb\n", str) == 0)
		sb(&stack->stack_b);
	if (ft_strcmp("rb\n", str) == 0)
		rb(&stack->stack_b);
	if (ft_strcmp("rrb\n", str) == 0)
		rrb(&stack->stack_b);
	if (ft_strcmp("rrr\n", str) == 0)
		rrr(&stack->stack_a, &stack->stack_b);
	if (ft_strcmp("ss\n", str) == 0)
		ss(&stack->stack_a, &stack->stack_b);
}

double	disorder_metrics(t_stack *head)
{
	int	mistakes;
	int	total_pair;
	int	i;
	int	j;
	int	len;

	mistakes = 0;
	total_pair = 0;
	len = count_nodes(head);
	if (len <= 1)
		return (0);
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			total_pair += 1;
			if (find_content(head, i + 1) > find_content(head, j + 1))
				mistakes += 1;
			j++;
		}
		i++;
	}
	return ((double)mistakes / total_pair);
}
