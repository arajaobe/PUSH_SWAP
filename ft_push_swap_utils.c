/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samrazaf <samrazaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:58:21 by arajaobe          #+#    #+#             */
/*   Updated: 2026/04/01 17:38:47 by samrazaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*head;

	head = malloc(sizeof(t_stack));
	if (!head)
		return (NULL);
	head -> content = content;
	head -> index = 0;
	head -> next = NULL;
	return (head);
}

int	count_nodes(t_stack *head)
{
	int		count;
	t_stack	*ptr;

	count = 0;
	if (head == NULL)
		return (0);
	ptr = head;
	while (ptr)
	{
		count++;
		ptr = ptr->next;
	}
	free(ptr);
	ptr = NULL;
	return (count);
}

int	find_content(t_stack *head, int pos)
{
	int		i;
	int		res;
	t_stack	*p;

	p = head;
	i = 1;
	if (pos == 0)
		return (0);
	while (i <= pos)
	{
		res = p->content;
		p = p->next;
		i++;
	}
	return (res);
}

int	find_index(t_stack *head, int pos)
{
	int		i;
	int		res;
	t_stack	*p;

	p = head;
	i = 1;
	if (pos == 0)
		return (0);
	while (i <= pos)
	{
		res = p->index;
		p = p->next;
		i++;
	}
	return (res);
}

int	search_content(t_stack **head, int find)
{
	int	i;
	int	len;

	len = count_nodes(*head);
	i = 1;
	while (i <= len)
	{
		if (find_content(*head, i) == find)
			return (i);
		i++;
	}
	return (0);
}
