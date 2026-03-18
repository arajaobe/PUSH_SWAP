
#include "ft_push_swap.h"

int bit_count(int max_index)
{
	int bits = 0;

	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}


int	is_value_zero(t_stack **head, int bits)
{
	int i;
	int res;
	int len;

	len = count_nodes(*head);
	res = 0;
	i = 1;
	while (i <= len)
	{
		if (((find_index(*head, i) >> bits) & 1) == 0)
			res = 1;
		i++;
	}
	return (res);
}


int	complex_sort(t_stack **a, t_stack **b, int *op_counters)
{
	int	len;
	int	*array;
	int count;
	int	bits;
	int i;
	int j;
	int value;

	count = 0;
	len = count_nodes(*a);
	array = malloc(sizeof(int) * len);
	array_sort(a, array);
	fill_index(a, array);
	bits = bit_count(find_max_bits(a, len));
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < len)
		{
			value = (*a)->index;
			if (((value >> i) & 1) == 0)
			{
				count += pb(a, b, op_counters);
			}
			else
				count += ra(a, op_counters);
			j++;
		}
		while (*b)
			count += pa(a, b, op_counters);
		i++;
	}

	return count;
}
