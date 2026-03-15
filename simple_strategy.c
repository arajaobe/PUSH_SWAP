
#include "ft_push_swap.h"

int	improved_simple_sort(t_stack **a, t_stack **b)
{
	int	min;
	int	max;
	int	dist_min;
	int	dist_max;
	int	len;
	int pos;
	int	count;

	count = 0;
	len = count_nodes(*a);

	while (*a)
	{
		min = find_min(a, len);
		max = find_max(a, len);
		dist_min = check_pos_from_edge(a, min);
		dist_max = check_pos_from_edge(a, max);
		if (dist_min - dist_max <= 2)
		{
			pos = search_content(a, min);
			if (pos > (len / 2) + 1)
			{
				while (pos != len + 1)
				{
					count += rra(a);
					pos++;
				}
			}
			else
			{
				while (pos != 1)
				{
					count += ra(a);
					pos--;
				}
			}
			count += pb(a, b);
			len = count_nodes(*a);
		}
		else
		{
			pos = search_content(a, max);
			if (pos > (len / 2) + 1)
			{
				while (pos != len + 1)
				{
					count += rra(a);
					pos++;
				}
			}
			else
			{
				while (pos != 1)
				{
					count += ra(a);
					pos--;
				}
			}
			count += pb(a, b);
			len = count_nodes(*a);
		}
	}
	count += push_findmax(a, b);

	return (count);
}
