/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaobe <arajaobe@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:58:21 by arajaobe          #+#    #+#             */
/*   Updated: 2026/03/25 09:45:45 by arajaobe         ###   ########.fr       */
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


/*t_stack	*list_arg_fillers(int argc, char **argv)
{
	t_stack *head;
	t_stack	*current;
	t_stack	*new_node;
	int		i;

	if (argc <= 1)
	{
		printf("error\n");
		return NULL;
	}
	head = ft_lstnew(ft_atoi(argv[1]));
	current = head;
	i = 2;
	while (i < argc)
	{
		new_node = ft_lstnew(ft_atoi(argv[i]));
		current->next = new_node;
		current = new_node;
		i++;
	}
	return head;
}*/
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
	return ((double)mistakes / total_pair);
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

int	intchr(int to_find, int *range, size_t size)
{
	int		res;
	size_t	i;

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

void	strategy_bench(t_strategy strat_bench, double disorder)
{
	char *strats;

	if (disorder < 0.2)
		strats = "O(n²)";
	else if (disorder < 0.5)
		strats = "O(n√n)";
	else
		strats = "O(n log n)";
	if (strat_bench == STRAT_SIMPLE)
		ft_printf(2, "[bench] strategy:  Simple / O(n²)\n");
	else if (strat_bench == STRAT_MEDIUM)
		ft_printf(2, "[bench] strategy:  Medium / O(n√n)\n");
	else if (strat_bench == STRAT_COMPLEX)
		ft_printf(2, "[bench] strategy:  Complex / O(n log n)\n");
	else
		ft_printf(2, "[bench] strategy:   Adaptive / %s\n", strats);
}
void	hundred(double disorder)
{
	double	before_point;
	int		res;
	double	decimal_point;

	//before_point = disorder;
	decimal_point = disorder * 100;
	res = decimal_point;
	before_point = decimal_point * 100 - (res * 100);
	res = before_point;
	if (res == 0)
		{
			ft_printf(2, "%f", decimal_point);
			ft_printf(2, "0%%\n");
		}
	else
		ft_printf(2, "%f%%\n", decimal_point);

}


void 	print_bench( t_strategy strat, int *op_counters, double disorder_metrics, int total_ops)
{

	ft_printf(2, "[bench] disorder:   ");
	hundred(disorder_metrics);
	strategy_bench( strat, disorder_metrics);
	ft_printf(2, "[bench] total_ops:  %d\n", total_ops);
	ft_printf(2, "[bench] sa: %d  sb: %d  ss: %d  pa: %d  pb: %d\n",
		op_counters[OP_SA],
		op_counters[OP_SB],
		op_counters[OP_SS],
		op_counters[OP_PA],
		op_counters[OP_PB]);
    ft_printf(2, "[bench] ra: %d  rb: %d  rr: %d  rra: %d  rrb: %d  rrr: %d\n",
		op_counters[OP_RA],
		op_counters[OP_RB],
		op_counters[OP_RR],
		op_counters[OP_RRA],
		op_counters[OP_RRB],
		op_counters[OP_RRR]);
}
int	duplicate(t_stack **a)
{
	int i;
	int j;
	int check;
	int pos;
	int size;

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

int	ft_isnumber(char *s)
{
	int i;

	i = 0;
	if (!s || !*s)
		return (0);
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (s[i] == '-' || s[i] == '+')
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


long 	ft_atol(const char *str)
{
	long	result;
	int 	sign ;
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

/*int	is_valid_digit(char *s)
{
    int i = 0;
    long val;


    if (!s || !*s)
        return 0;

    if (s[i] == '+' || s[i] == '-')
        i++;

    if (!s[i])
        return 0;


    while (s[i])
    {
        if (s[i] < '0' || s[i] > '9')
            return 0;
        i++;
    }


    val = ft_atol(s);
    if (val < -2147483648 || val > 2147483647)
        return 0;

    return 1;
}*/

int	is_valid_digit(char *s)
{
	long	val;

	val = ft_atol(s);
	if (val < -2147483648 || val > 2147483647)
		return 0;
	return (1);
}



//chunks 3
//chunks 3 -1 = 2
// start :3   | end : 5
// 21  13 9 7	 6 8 12
//tab : 0 1 4 5 6 7 8 9 12 13 21 82

// 4
// 5
// 1
// 0
// 2
//B  2 0 1
