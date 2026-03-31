/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_three_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samrazaf <samrazaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 18:22:09 by samrazaf          #+#    #+#             */
/*   Updated: 2026/03/31 18:38:42 by samrazaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	short_op(t_parse_result *ptr, int *op_counters, int len);
static int	mini_func(t_stack *x);

int	short_sort(t_parse_result *ptr, int *op_counters)
{
	int count;
	int	len;
	int stack_len;

	count = 0;
	len = count_nodes(ptr->stack_a);
	stack_len = len;
	while (stack_len != 3)
	{
		count += short_op(ptr, op_counters, len);
		count += pb(&ptr->stack_a, &ptr->stack_b, op_counters);
		len = count_nodes(ptr->stack_a);
		stack_len--;
	}
	count += mini_sort(ptr, op_counters);
	while (ptr->stack_b)
		count += pa(&ptr->stack_a, &ptr->stack_b, op_counters);
	return (count);
}
int	mini_sort(t_parse_result *a, int *op_counters)
{
	t_stack	*x;
	int		count;
	int		i;

	count = 0;
	x = a->stack_a;
	i = mini_func(x);
	if (i == 1)
		count += ra(&a->stack_a, op_counters);
	else if (i == 2)
	{
		count += sa(&a->stack_a, op_counters);
		count += rra(&a->stack_a, op_counters);
	}
	else if (i == 3)
		count += rra(&a->stack_a, op_counters);
	else if (i == 4)
		count += sa(&a->stack_a, op_counters);
	else if (i == 5)
	{
		count += rra(&a->stack_a, op_counters);
		count += sa(&a->stack_a, op_counters);
	}
	return (count);
}

int	tiny_sort(t_parse_result *stack, int *op_counters)
{
	int first;
	int second;
	int count;

	count = 0;
	first = (stack->stack_a)->content;
	second = (stack->stack_a)->next->content;
	if (first > second)
		count = ra(&stack->stack_a, op_counters);
	return (count);
}

static int	mini_func(t_stack *x)
{
	if ((x->content > x->next->content)
		&& (x->content > x->next->next->content)
		&& (x->next->content < x->next->next->content))
		return (1);
	else if ((x->content > x->next->content)
		&& (x->content > x->next->next->content)
		&& (x->next->content > x->next->next->content))
		return (2);
	else if ((x->content < x->next->content)
		&& (x->content > x->next->next->content)
		&& (x->next->content > x->next->next->content))
		return (3);
	else if ((x->content > x->next->content)
		&& (x->content < x->next->next->content)
		&& (x->next->content < x->next->next->content))
		return (4);
	else if ((x->content < x->next->content)
		&& (x->content < x->next->next->content)
		&& (x->next->content > x->next->next->content))
		return (5);
	else
		return (0);
}


static	int	short_op(t_parse_result *ptr, int *op_counters, int len)
{
	int i;
	int count;

	count = 0;
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
	return (count);
}


