/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samrazaf <samrazaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 18:03:33 by samrazaf          #+#    #+#             */
/*   Updated: 2026/04/07 19:42:07 by samrazaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"
#include "get_next_line/get_next_line.h"
#include "ft_printf/ft_printf.h"

int	duplicate(t_stack **a)
{
	int	i;
	int	j;
	int	check;
	int	pos;
	int	size;

	size = count_nodes(*a);
	check = 0;
	i = 1;
	while (i <= size)
	{
		pos = find_content(*a, i);
		j = i + 1;
		while (j <= size)
		{
			if (pos == find_content(*a, j))
			{
				check = 1;
				return (check);
			}
			j++;
		}
		i++;
	}
	return (check);
}

static void	error_check(t_parse_result *stack)
{
	if (duplicate(&stack->stack_a))
	{
		ft_lstclear(&stack->stack_a);
		ft_printf(2, "Error\n");
		exit(1);
	}
}

static void	execute_function(t_parse_result *stack, char *str)
{
	if (ft_strcmp("pa", str))
		pa(&stack->stack_a, &stack->stack_b);
	if (ft_strcmp("sa", str))
		sa(&stack->stack_a);
	if (ft_strcmp("ra", str))
		ra(&stack->stack_a);
	if (ft_strcmp("rra", str))
		rra(&stack->stack_a);
	if (ft_strcmp("pb", str))
		pb(&stack->stack_a, &stack->stack_b);
	if (ft_strcmp("sb", str))
		sb(&stack->stack_b);
	if (ft_strcmp("rb", str))
		rb(&stack->stack_b);
	if (ft_strcmp("rrb", str))
		rrb(&stack->stack_b);
	if (ft_strcmp("rrr", str))
		rrr(&stack->stack_a, &stack->stack_b);
	if (ft_strcmp("ss", str))
		ss(&stack->stack_a, &stack->stack_b);
}

static int	check_upcrease(t_parse_result *stack)
{
	int	i;
	int	j;

	j = count_nodes(stack->stack_a);
	i = 0;
	while (j > i)
	{
		if (&stack->stack_a->content > &stack->stack_a->next->content)
			return (0);
		i ++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_parse_result	parse;
	char	*line;

	parse = list_arg_fillers_new(argc, argv);
	parse.stack_b = NULL;
	error_check(&parse);
	line = get_next_line(0);
	if (!line)
		return (0);
	while (line)
	{
		execute_function(&parse, line);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (check_upcrease(&parse))
		ft_printf(1, "OK");
	else
		ft_printf(1, "KO");
	return (0);
}
