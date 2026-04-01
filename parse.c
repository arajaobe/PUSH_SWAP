/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samrazaf <samrazaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 17:53:26 by samrazaf          #+#    #+#             */
/*   Updated: 2026/04/01 17:53:28 by samrazaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	handle_flag(char *arg, t_parse_result *result)
{
	if (ft_strcmp(arg, "--simple") == 0)
		result->strategy = STRAT_SIMPLE;
	else if (ft_strcmp(arg, "--medium") == 0)
		result->strategy = STRAT_MEDIUM;
	else if (ft_strcmp(arg, "--complex") == 0)
		result->strategy = STRAT_COMPLEX;
	else if (ft_strcmp(arg, "--adaptive") == 0)
		result->strategy = STRAT_ADAPTIVE;
	else if (ft_strcmp(arg, "--bench") == 0)
		result->bench_mode = 1;
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

static void	append_node(t_stack **head, t_stack **current, t_stack *new_node)
{
	if (!*head)
	{
		*head = new_node;
		*current = *head;
	}
	else
	{
		(*current)->next = new_node;
		*current = new_node;
	}
}

static void	parse_tab(char **tab, t_stack **head, t_stack **current)
{
	t_stack	*new_node;
	int		j;

	j = 0;
	while (tab[j])
	{
		if (!ft_isnumber(tab[j]) || !is_valid_digit(tab[j]))
		{
			ft_free_split(tab);
			ft_lstclear(head);
			ft_printf(2, "Error\n");
			exit(1);
		}
		new_node = ft_lstnew(ft_atoi(tab[j]));
		append_node(head, current, new_node);
		j++;
	}
}

void	handle_arg(char *arg, t_stack **head, t_stack **current)
{
	char	**tab;

	tab = ft_split(arg, ' ');
	if (!tab || !tab[0])
	{
		ft_printf(2, "Error\n");
		exit(1);
	}
	parse_tab(tab, head, current);
	ft_free_split(tab);
}
