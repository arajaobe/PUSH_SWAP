/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaobe <arajaobe@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:58:31 by arajaobe          #+#    #+#             */
/*   Updated: 2026/03/16 17:04:53 by arajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_push_swap.h"


static int	swap(t_stack **head)
{
	int temp;

	if (!*head || !(*head)->next)
		return (0);
	temp = (*head)->content;
	(*head)->content = (*head)->next->content;
	(*head)->next->content = temp;
	return (1);
}
int	sa(t_stack **a)
{
	int x;

	x = swap(a);
	printf("sa\n");
	return (x);
}

int	sb(t_stack **b)
{
	int x;

	x = swap(b);
	printf("sb\n");
	return (x);

}

int	ss(t_stack **a, t_stack **b)
{
	int x;
	int y;
	x = swap(a);
	y = swap(b);
	printf("ss\n");
	return (x + y);
}

int	pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!a)
		return (0);
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	printf("pb\n");
	return (1);
}

int	pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!b)
		return (0);
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	printf("pa\n");
	return (1);
}

int	reverse_reverse(t_stack	**head)
{
	int	current;
	int previous;
	t_stack	*p;

	if (!*head)
		return (0);
	p = *head;
	previous = p->content;
	while (p->next)
	{
		current = p->next->content;
		p->next->content = previous;
		previous = current;
		p = p->next;
	}
	(*head)->content = previous;
	return (1);
}

int	reverse(t_stack	**head)
{
	int	current;
	int after;
	t_stack	*p;

	if (!*head)
		return (0);
	p = *head;
	current = p->content;
	while (p->next)
	{
		after = p->next->content;
		p->content = after;
		p = p->next;
	}
	p->content = current;
	return (1);
}
int	ra(t_stack **a)
{
	int	x;

	x = reverse(a);
	printf("ra\n");
	return (x);
}

int	rb(t_stack **b)
{
	int	x;

	x = reverse(b);
	printf("rb\n");
	return (x);
}

int	rr(t_stack **a, t_stack **b)
{
	int	x;
	int	y;

	x = reverse(a);
	y = reverse(b);
	printf("rr\n");
	return (x + y);
}

int	rra(t_stack **a)
{
	int x;

	x = reverse_reverse(a);
	printf("rra\n");
	return (x);
}

int	rrb(t_stack **b)
{
	int	x;
	x = reverse_reverse(b);
	printf("rrb\n");
	return (x);
}

int	rrr(t_stack **a, t_stack **b)
{
	int	x;
	int	y;

	x = reverse_reverse(a);
	y = reverse_reverse(b);
	printf("rrr\n");
	return (x + y);
}
