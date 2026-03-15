
#include "ft_push_swap.h"

int	medium_core(t_stack **a, t_stack **b, int *array)
{
	static int	i;
	int j;
	int count;
	int len;
	int	*temp;
	int chunk;

	len = count_nodes(*a);
	chunk = int_sqrt(len);
	i = 0;
	j = 0;
	count = 0;
	while (i < len)
	{
		if (i + chunk > len)
			chunk = len - i;
		temp = malloc(sizeof(int) * chunk);
		i = temporary_medium(array, chunk, i, temp);
		count += rotate_medium(a, b, temp, chunk);
		free(temp);
		temp = NULL;
	}
	return (count);
}

int	medium_sort(t_stack **a, t_stack **b)
{
	int	len;
	int	*array;
	int count;

	len = count_nodes(*a);
	array = malloc(sizeof(int) * len);
	array_sort(a, array);
	count += medium_core(a, b, array);
	count += push_findmax(a,b);
	return count;
}

int	simple_sort(t_stack **a, t_stack **b)
{
	int count;
	int	i;
	int	len;

	count = 0;
	len = count_nodes(*a);
	while (*a)
	{
		i = search_content(a, find_min(a, len));

		if (i > (len / 2) + 1)
		{
			while (i != len + 1)
			{
				count += rra(a);
				i++;
			}
		}
		else
		{
			while (i != 1)
			{
				count += ra(a);
				i--;
			}
		}
		count += pb(a, b);
		len = count_nodes(*a);
	}
	while (*b)
	{
		count += pa(a,b);
	}

	return (count);
}
