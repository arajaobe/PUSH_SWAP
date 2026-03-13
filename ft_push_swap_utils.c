/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaobe <arajaobe@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:58:21 by arajaobe          #+#    #+#             */
/*   Updated: 2026/03/11 17:44:20 by arajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_push_swap.h"



void print_index(t_stack *head)
{
	t_stack *p;
	p = head;

	while (p != NULL)
	{
		printf("%d \n", p -> index);

		p = p -> next;
	}
}
void    print_num(t_stack *a, t_stack *b)
{
	t_stack *pa;
	t_stack *pb;

	pa = a;
	pb = b;
	printf("a\tb\n");
	while (pa || pb)
	{
		if (pa)
		{
			printf("%d", pa->content);
			pa = pa->next;
		}
		else
			printf(" ");
		printf("\t");
		if (pb)
		{
			printf("%d", pb->content);
			pb = pb->next;
		}
		else
			printf(" ");
		printf("\n");
		}
}

void	print_stacks(t_stack *a, t_stack *b)
{
	printf("\n");
	print_num(a, b);
	printf("\n");
}

t_stack	*ft_lstnew(int	content)
{
	t_stack	*head;

	head = malloc(sizeof(t_stack));
	if (!head)
		return (NULL);
	head -> content = content;
	head -> next = NULL;
	return (head);
}

t_stack	*list_fillers(int stop, ...)
{
	va_list args;
	va_start(args, stop);
	t_stack *one;
	t_stack *two;
	t_stack *three;
	int i;

	one = ft_lstnew( va_arg(args, int));
	if (stop == 1)
		return one;
	two = ft_lstnew(va_arg(args, int));
	one->next = two;
	if (stop == 2)
		return one;
	i = 2;
	three = one->next;
	while (i < stop)
	{
		two = ft_lstnew(va_arg(args, int));;
		three->next = two;
		three = three->next;
		i++;
	}
	va_end(args);
	return one;
}
int	count_nodes(t_stack *head)
{
	int	count;
	t_stack *ptr;

	count = 0;
	if (head == NULL)
		return 0;
	ptr = head;
	while (ptr)
	{
		count++;
		ptr = ptr->next;
	}
	free(ptr);
	ptr = NULL;
	return count;
}

int	find_content(t_stack *head, int pos)
{
	int i;
	int	res;
	t_stack *p;

	p = head;
	i = 1;
	if (pos == 0)
		return 0;
	while (i <= pos)
	{
		res = p->content;
		p = p->next;
		i++;
	}
	return res;
}

int search_content(t_stack **head, int find)
{
	int i;
	int len;

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

t_stack	*find_link(t_stack *head, int pos)
{
	int i;

	t_stack *p;
	t_stack *res;

	p = head;
	i = 1;
	if (pos == 0)
		return 0;
	while (i <= pos)
	{
		res = p;
		p = p->next;
		i++;
	}
	return res;
}


void	fill_index(t_stack **head, int	*array)
{
	int i;
	int	j;
	int len;
	t_stack	*temp;

	temp = NULL;
	len = count_nodes(*head);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (array[i] == find_content(*head, j+1))
			{
				temp = find_link(*head, j+1 );
				temp->index = i;
				break;
			}
			j++;
		}
		temp = NULL;
		i++;
	}

}

float	disorder_metrics(t_stack *head)
{
	float	result;
	int	mistakes;
	int total_pair;
	int	i;
	int	j;
	int len;

	mistakes = 0;
	total_pair = 0;
	len = count_nodes(head);

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			total_pair += 1;
			if (find_content(head, i+1) > find_content(head, j+1))
			{
				mistakes += 1;
			}
			j++;
		}
		i++;
	}
	result = (float)mistakes / total_pair;
	return (result);
}
void	insertsort(int	*tab, int size)
{
	int i;
	int j;
	int key;

	i = 1;
	while (i < size)
	{
		key = tab[i];
		j = i - 1;
		while (j >=0 && tab[j] > key)
		{
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = key;
		i++;
	}
}
//chunks 3
//chunks 3 -1 = 2
// start :3   | end : 5
// 21  13 9 7 6 8 12
//tab : 0 1 4 5 6 7 8 9 12 13 21 82

// 4
// 5
// 1
// 0
// 2
//B  2 0 1
