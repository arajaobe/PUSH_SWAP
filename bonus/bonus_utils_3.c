/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samrazaf <samrazaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 18:55:02 by samrazaf          #+#    #+#             */
/*   Updated: 2026/04/08 18:56:33 by samrazaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i ++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	is_flag(char *arg)
{
	if (ft_strcmp(arg, "--simple") == 0)
		return (1);
	if (ft_strcmp(arg, "--medium") == 0)
		return (1);
	if (ft_strcmp(arg, "--complex") == 0)
		return (1);
	if (ft_strcmp(arg, "--adaptive") == 0)
		return (1);
	if (ft_strcmp(arg, "--bench") == 0)
		return (1);
	return (0);
}

void	error_check(t_parse_result *stack)
{
	if (duplicate(&stack->stack_a))
	{
		ft_lstclear(&stack->stack_a);
		ft_printf(2, "Error\n");
		exit(1);
	}
}

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

t_parse_result	list_arg_fillers_new(int argc, char **argv)
{
	t_parse_result	result;
	t_stack			*head;
	t_stack			*current;
	int				i;

	head = NULL;
	current = NULL;
	result.stack_a = NULL;
	if (argc <= 1)
		return (result);
	i = 1;
	while (i < argc)
	{
		if (is_flag(argv[i]) == 0)
			handle_arg(argv[i], &head, &current);
		i++;
	}
	result.stack_a = head;
	return (result);
}
