/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samrazaf <samrazaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:58:21 by arajaobe          #+#    #+#             */
/*   Updated: 2026/03/22 16:29:24 by samrazaf         ###   ########.fr       */
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
	head -> index = 0;
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

/*t_stack	*list_arg_fillers(int argc, char **argv)
{

	t_stack *one;
	t_stack *two;
	t_stack *three;
	int i;
	int j;

	int *tab;
	tab = malloc (sizeof(int) * (argc - 1));

	for(j = 0; j < argc - 1; j++)
		tab[j] = ft_atoi(argv[j + 1]);

	one = ft_lstnew(tab[0]);
	if (argc == 1)
		return one;
	two = ft_lstnew(tab[1]);
	one->next = two;
	if (argc == 2)
		return one;
	i = 2;
	three = one->next;
	while (i < j)
	{
		two = ft_lstnew(tab[i]);
		three->next = two;
		three = three->next;
		i++;
	}
	return one;

}*/


//t_stack	*list_arg_fillers(int argc, char **argv)
//{
//	t_stack *head;
//	t_stack	*current;
//	t_stack	*new_node;
//	int		i;

//	if (argc <= 1)
//	{
//		printf("error\n");
//		return NULL;
//	}
//	head = ft_lstnew(ft_atoi(argv[1]));
//	current = head;
//	i = 2;
//	while (i < argc)
//	{
//		new_node = ft_lstnew(ft_atoi(argv[i]));
//		current->next = new_node;
//		current = new_node;
//		i++;
//	}
//	return head;
//}

int	check_flags(char *str)
{
	if ((!ft_strcmp(str, "--simple")) ||
	(!ft_strcmp(str, "--medium")) ||
	(!ft_strcmp(str, "--complex")) ||
	(!ft_strcmp(str, "--adaptive")))
		return (0);
	return (1);
}

int	check_flags_position(int argc, char **argv)
{
	if (!check_flags(argv[1]) && check_flags(argv[argc - 1]))
		return (1);
	else if (!check_flags(argv[argc - 1]) && check_flags(argv[1]))
		return (argc - 1);
	else
		return (0);
}

int	check_argv(int argc, char **argv)
{
	int	i;
	int	j;

	if (!check_flags_position(argc, argv))
		return (0);
	else if (check_flags_position(argc, argv) == 1)
		j = 2;
	else
	{
		j = 1;
		argc = argc - 1;
	}
	while (j < argc)
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			if (!ft_isdigit(argv[j][i]) && argv[j][i] != ' ')
				return (0);
			i ++;
		}
		j ++;
	}
	return (1);
}

int	check_argv_adaptive(int position, char **argv)
{
	if (!ft_strcmp(argv[position], "--adaptive"))
		return (1);
	return (0);
}

int	use_fonction(t_stack **a, t_stack **b, int *op_operation, char **argv)
{
	int	i;
	int	count;

	i = 1;
	count = 0;

	while (argv[i])
	{
		if (ft_strcmp(argv[i], "--simple"))
			count = improved_simple_sort(a, b, op_operation);
		else if (ft_strcmp(argv[i], "--medium"))
			count = medium_sort(a, b, op_operation);
		else if (ft_strcmp(argv[i], "--complex"))
			count = complex_sort(a, b, op_operation);
		i ++;
	}
	return (count);
}

int	use_adaptive_fonction(t_stack **a, t_stack **b, int *op_operation, float disorder)
{
	int		count;

	if (disorder < 0.2)
	{
		count = improved_simple_sort(a, b, op_operation);
		printf("simple");
	}
	else if (disorder >= 0.2 && disorder < 0.5)
	{
		count = medium_sort(a, b, op_operation);
		printf("medium");
	}
	else
	{
		count = complex_sort(a, b, op_operation);
		printf("complex");
	}
	return (count);
}
t_stack	*list_arg_fillers(int argc, char **argv)
{
	t_stack *head;
	t_stack	*current;
	t_stack	*new_node;
	int		i;
	int		j;
	char	**tab;

	if (argc < 1 || !check_argv(argc, argv))
	{
		printf("error\n");
		return NULL;
	}
	if (check_flags_position(argc, argv) == 1)
		i = 2;
	else if (check_flags_position(argc, argv) > 1)
	{
		i = 1;
		argc = argc - 1;
	}
	if (ft_strchr((argv[i]), ' '))
	{
		tab = ft_split(argv[i], ' ');
		head = ft_lstnew(ft_atoi(tab[0]));
		current = head;
		j = 1;
		while (tab[j])
		{
			new_node = ft_lstnew(ft_atoi(tab[j]));
			current->next = new_node;
			current = new_node;
			j ++;
		}
	}
	else
	{
		head = ft_lstnew(ft_atoi(argv[i]));
		current = head;
	}
	i ++;
	while (i < argc)
	{
		if (ft_strchr((argv[i]), ' '))
		{
			tab = ft_split(argv[i], ' ');
			j = 0;
			while (tab[j])
			{
				new_node = ft_lstnew(ft_atoi(tab[j]));
				current->next = new_node;
				current = new_node;
				j ++;
			}
		}
		else
		{
			new_node = ft_lstnew(ft_atoi(argv[i]));
			current->next = new_node;
			current = new_node;
		}
		i++;
	}
	return head;
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

int	find_index(t_stack *head, int pos)
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
		res = p->index;
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

float	disorder_metrics(t_stack *head)
{
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
	return ((float)mistakes / total_pair);
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

int int_sqrt(int n)
{
	if (n == 0 || n == 1)
		return n;
	int x = n / 2;
	while (x > n / x)
	{
		x = (x + n / x) / 2;
	}
	return x;
}

int find_max_bits(t_stack **head, int len)
{
	int	max;
	int i;

	max = find_index(*head, 1);
	i = 2;
	while (i <= len)
	{
		if (find_index(*head, i) > max)
			max = find_index(*head,i);
		i++;
	}
	return (max);
}

int find_max(t_stack **head, int len)
{
	int	max;
	int i;

	max = find_content(*head, 1);
	i = 2;
	while (i <= len)
	{
		if (find_content(*head, i) > max)
			max = find_content(*head,i);
		i++;
	}
	return (max);
}

int find_min (t_stack **head, int len)
{
	int min;
	int i;

	min = find_content(*head, 1);
	i = 2;
	while (i <= len)
	{
		if (find_content(*head, i) < min)
			min = find_content(*head, i);
		i++;
	}
	return (min);
}

int	intchr(int to_find, int *range, int size)
{
	int res;
	int i;

	res = 0;
	i = 0;
	while (i < size)
	{
		if (to_find == range[i])
			res = 1;
		i++;
	}
	return (res);
}

void array_sort(t_stack **a, int *array)
{
	int	len;
	int i;

	len = count_nodes(*a);
	i = 0;
	while (i < len)
	{
		array[i] = find_content(*a,i+1);
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
	if (pos <= (len / 2) + 1 ) // first half
		diff = pos - 1;
	else
		diff =  (len + 1) - pos;
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

/*void	strategies(float disorder, char *strategy)
{
	char *strats;

	if (disorder < 0.2)
		strats = "O(n²)";
	else if (disorder < 0.5)
		strats = "O(n√n)";
	else
		strats = "O(n log n)";
	if (strategy == "--simple")
		printf("[bench] strategy:  Simple / O(n²)\n");
	else if (strategy == "--medium")
		printf("[bench] strategy:  Medium / O(n√n)\n");
	else if (strategy == "--complex")
		printf("[bench] strategy:  Complex / O(n log n)\n");
	else  if (strategy == "--adaptive" || strategy =="")
		printf("[bench] strategy:   Adaptive / %s\n", strats);
}*/

void 	print_bench(int *op_counters, float disorder_metrics, int total_ops)
{
	printf("[bench] disorder:   %.2f%%\n", disorder_metrics * 100);
	//strategies(disorder_metrics, strate);
	printf("[bench] total_ops:  %d\n", total_ops);
	printf("[bench] sa: %d  sb: %d  ss: %d  pa: %d  pb: %d\n",
		op_counters[OP_SA],
		op_counters[OP_SB],
		op_counters[OP_SS],
		op_counters[OP_PA],
		op_counters[OP_PB]);
    printf("[bench] ra: %d  rb: %d  rr: %d  rra: %d  rrb: %d  rrr: %d\n",
		op_counters[OP_RA],
		op_counters[OP_RB],
		op_counters[OP_RR],
		op_counters[OP_RRA],
		op_counters[OP_RRB],
		op_counters[OP_RRR]);
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
