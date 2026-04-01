/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samrazaf <samrazaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 17:01:18 by samrazaf          #+#    #+#             */
/*   Updated: 2026/04/01 17:23:23 by samrazaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack	*find_link(t_stack *head, int pos)
{
	int		i;
	t_stack	*p;
	t_stack	*res;

	p = head;
	i = 1;
	if (pos == 0)
		return (0);
	while (i <= pos)
	{
		res = p;
		p = p->next;
		i++;
	}
	return (res);
}

void	fill_index(t_stack **head, int	*array)
{
	int		i;
	int		j;
	int		len;
	t_stack	*temp;

	len = count_nodes(*head);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (array[i] == find_content(*head, j + 1))
			{
				temp = find_link(*head, j + 1);
				temp->index = i;
				break ;
			}
			j++;
		}
		temp = NULL;
		i++;
	}
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

double	disorder_metrics(t_stack *head)
{
	int	mistakes;
	int	total_pair;
	int	i;
	int	j;
	int	len;

	mistakes = 0;
	total_pair = 0;
	len = count_nodes(head);
	if (len == 1)
		return (0);
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			total_pair += 1;
			if (find_content(head, i + 1) > find_content(head, j + 1))
				mistakes += 1;
			j++;
		}
		i++;
	}
	return ((double)mistakes / total_pair);
}

void	insertsort(int *tab, int size)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < size)
	{
		key = tab[i];
		j = i - 1;
		while (j >= 0 && tab[j] > key)
		{
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = key;
		i++;
	}
}
