/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samrazaf <samrazaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 18:03:33 by samrazaf          #+#    #+#             */
/*   Updated: 2026/04/08 19:40:44 by samrazaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"
#include "get_next_line/get_next_line.h"
#include "ft_printf/ft_printf.h"

int	main(int argc, char **argv)
{
	t_parse_result	parse;
	char			*line;
	double			x;

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
	x = disorder_metrics(parse.stack_a);
	if (x == 0 && parse.stack_b == NULL)
		ft_printf(1, "OK");
	else
		ft_printf(1, "KO");
	return (0);
}
