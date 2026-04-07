/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samrazaf <samrazaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 18:36:43 by samrazaf          #+#    #+#             */
/*   Updated: 2026/04/07 19:35:08 by samrazaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10;
		res = res + (nptr[i] - '0');
		i++;
	}
	return (sign * res);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

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

int	is_valid_digit(char *s)
{
	long	val;

	val = ft_atol(s);
	if (val < -2147483648 || val > 2147483647)
		return (0);
	return (1);
}

int	ft_isnumber(char *s)
{
	int	i;

	i = 0;
	if (!s || !*s)
		return (0);
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (s[i] == '-' || s[i] == '+')
		return (0);
	if (ft_strlen(s) >= 20)
		return (0);
	if (!ft_isdigit((unsigned char)s[i]))
		return (0);
	while (s[i])
	{
		if (!ft_isdigit((unsigned char)s[i]))
			return (0);
		i++;
	}
	return (1);
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
		if (!is_flag(argv[i]))
			handle_arg(argv[i], &head, &current);
		i++;
	}
	result.stack_a = head;
	return (result);
}
