/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samrazaf <samrazaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:59:58 by samrazaf          #+#    #+#             */
/*   Updated: 2026/04/01 17:07:21 by samrazaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	strategy_bench(t_strategy strat_bench, double disorder)
{
	char	*strats;

	if (disorder < 0.2)
		strats = "O(n²)";
	else if (disorder < 0.5)
		strats = "O(n√n)";
	else
		strats = "O(n log n)";
	if (strat_bench == STRAT_SIMPLE)
		ft_printf(2, "[bench] strategy:  Simple / O(n²)\n");
	else if (strat_bench == STRAT_MEDIUM)
		ft_printf(2, "[bench] strategy:  Medium / O(n√n)\n");
	else if (strat_bench == STRAT_COMPLEX)
		ft_printf(2, "[bench] strategy:  Complex / O(n log n)\n");
	else
		ft_printf(2, "[bench] strategy:   Adaptive / %s\n", strats);
}

static void	hundred(double disorder)
{
	double	before_point;
	int		res;
	double	decimal_point;

	decimal_point = disorder * 100;
	res = decimal_point;
	before_point = decimal_point * 100 - (res * 100);
	res = before_point;
	if (res == 0)
	{
		ft_printf(2, "%f", decimal_point);
		ft_printf(2, "0%%\n");
	}
	else
		ft_printf(2, "%f%%\n", decimal_point);
}

void	print_bench(t_strategy strat, int *op_counters,
	double disorder_metrics, int total_ops)
{
	ft_printf(2, "[bench] disorder:   ");
	hundred(disorder_metrics);
	strategy_bench(strat, disorder_metrics);
	ft_printf(2, "[bench] total_ops:  %d\n", total_ops);
	ft_printf(2, "[bench] sa: %d  sb: %d  ss: %d  pa: %d  pb: %d\n",
		op_counters[OP_SA],
		op_counters[OP_SB],
		op_counters[OP_SS],
		op_counters[OP_PA],
		op_counters[OP_PB]);
	ft_printf(2, "[bench] ra: %d  rb: %d  rr: %d  rra: %d  rrb: %d  rrr: %d\n",
		op_counters[OP_RA],
		op_counters[OP_RB],
		op_counters[OP_RR],
		op_counters[OP_RRA],
		op_counters[OP_RRB],
		op_counters[OP_RRR]);
}
