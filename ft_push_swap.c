/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaobe <arajaobe@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:37:45 by arajaobe          #+#    #+#             */
/*   Updated: 2026/03/25 14:47:07 by arajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_push_swap.h"

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
	if (duplicate(&parse.stack_a))
	{
		ft_lstclear(&parse.stack_a);
		ft_printf(2, "error\n");
		exit(1);
	}
	x = run_strategy(parse.strategy, &parse, op_counters);
	if (parse.bench_mode)
		print_bench(parse.strategy, op_counters, disorder, x);
	return (0);
}

