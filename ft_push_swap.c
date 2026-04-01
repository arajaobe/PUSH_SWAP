/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaobe <arajaobe@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:37:45 by arajaobe          #+#    #+#             */
/*   Updated: 2026/04/01 16:22:25 by arajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_push_swap.h"

static void	error_check(t_parse_result *stack);

int main(int argc, char **argv)
{
	t_parse_result parse;
	int 	x;
	double 	disorder;
	int op_counters[11];

	x = 0;
	ft_memset(op_counters, 0, sizeof(op_counters));
	parse = list_arg_fillers_new(argc, argv);
	disorder = disorder_metrics(parse.stack_a);
	parse.stack_b = NULL;
	error_check(&parse);
	x = run_strategy(parse.strategy, &parse, op_counters);
	if (parse.bench_mode)
		print_bench(parse.strategy, op_counters, disorder, x);
	return (0);
}

static void	error_check(t_parse_result *stack)
{
	if (stack->stack_a == NULL)
	{
		ft_printf(2, "Error\n");
		exit(1);
	}
	if (duplicate(&stack->stack_a))
	{
		ft_lstclear(&stack->stack_a);
		ft_printf(2, "Error\n");
		exit(1);
	}
}
