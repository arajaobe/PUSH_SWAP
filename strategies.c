/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaobe <arajaobe@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:38:01 by arajaobe          #+#    #+#             */
/*   Updated: 2026/04/01 14:32:34 by arajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_push_swap.h"


int adaptive_sort(t_parse_result *stack, int *op_operation, double disorder)
{
	int		count;

	count = 0;
	if (disorder < 0.2)
	{
		count = improved_simple_sort(stack, op_operation);
	}
	else if (disorder >= 0.2 && disorder < 0.5)
	{
		count = medium_sort(stack, op_operation);
	}
	else
	{
		count = complex_sort(stack, op_operation);
	}
	return (count);
}

int run_strategy(t_strategy strat, t_parse_result *stack, int *op_counters)
{
	double 	disorder;
	int 	count;

	count = 0;
	disorder = disorder_metrics(stack->stack_a);
	if (strat == STRAT_SIMPLE)
		count =  improved_simple_sort(stack, op_counters);
	else if (strat == STRAT_MEDIUM)
		count =  medium_sort(stack, op_counters);
	else if (strat == STRAT_COMPLEX)
		count = complex_sort(stack, op_counters);
	else
		count = adaptive_sort(stack, op_counters, disorder);
	return (count);
}

t_parse_result	list_arg_fillers_new(int argc, char **argv)
{
	t_parse_result	result;
	t_stack			*head;
	t_stack			*current;
	int				i;

	head = NULL;
	current = NULL;
	result.stack_a = NULL;
	result.bench_mode = 0;
	result.strategy = STRAT_ADAPTIVE;
	error_arg(argc);
	i = 1;
	while (i < argc)
	{
		if (is_flag(argv[i]))
			handle_flag(argv[i], &result);
		else
			handle_arg(argv[i], &head, &current);
		i++;
	}
	result.stack_a = head;
	return (result);
}
