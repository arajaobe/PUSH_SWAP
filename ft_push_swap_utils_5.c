/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils_5.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samrazaf <samrazaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 17:01:27 by samrazaf          #+#    #+#             */
/*   Updated: 2026/04/01 17:30:41 by samrazaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	array_sort(t_stack **a, int *array)
{
	int	len;
	int	i;

	len = count_nodes(*a);
	i = 0;
	while (i < len)
	{
		array[i] = find_content(*a, i + 1);
		i++;
	}
	insertsort(array, len);
}

int	check_pos_from_edge(t_stack **head, int check)
{
	int	pos;
	int	len;
	int	diff;

	diff = 0;
	len = count_nodes(*head);
	pos = search_content(head, check);
	if (pos <= (len / 2) + 1)
		diff = pos - 1;
	else
		diff = (len + 1) - pos;
	return (diff);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*d;

	d = s;
	while (n--)
		*d++ = (unsigned char)c;
	return (s);
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
