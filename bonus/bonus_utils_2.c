/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samrazaf <samrazaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 18:52:06 by samrazaf          #+#    #+#             */
/*   Updated: 2026/04/08 18:53:31 by samrazaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

void	ft_lstclear(t_stack **lst)
{
	t_stack	*temp;

	if (!lst)
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	append_node(t_stack **head, t_stack **current, t_stack *new_node)
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

void	parse_tab(char **tab, t_stack **head, t_stack **current)
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
		ft_free_split(tab);
		ft_lstclear(head);
		exit(1);
	}
	parse_tab(tab, head, current);
	ft_free_split(tab);
}
