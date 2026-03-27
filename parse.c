
#include "ft_push_swap.h"

t_parse_result	list_arg_fillers_new(int argc, char **argv)
{
	t_parse_result result;
	t_stack *head;
	t_stack *current;
	t_stack *new_node;
	char	**tab;
	int i;
	int j;

	head = NULL;
	current = NULL;
	result.stack_a = NULL;
	result.bench_mode = 0;
	result.strategy = STRAT_ADAPTIVE;
	if (argc <= 1)
		return (result);
	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--simple") == 0)
			result.strategy = STRAT_SIMPLE;
		else if (ft_strcmp(argv[i], "--medium") == 0)
			result.strategy = STRAT_MEDIUM;
		else if (ft_strcmp(argv[i], "--complex") == 0)
			result.strategy = STRAT_COMPLEX;
		else if (ft_strcmp(argv[i], "--adaptive") == 0)
			result.strategy = STRAT_ADAPTIVE;
		else if (ft_strcmp(argv[i], "--bench") == 0)
			result.bench_mode = 1;
		else
		{
			tab = ft_split(argv[i], ' ');
			if (!tab || !tab[0])
			{
				ft_printf(2, "Error\n");
				exit(1);
			}
			j = 0;
			while (tab[j])
			{
				if (!ft_isnumber(tab[j]) || !is_valid_digit(tab[j]))
				{
					ft_free_split(tab);
					ft_lstclear(&head);
					ft_printf(2, "Error\n");
					exit(1);
				}
				new_node = ft_lstnew(ft_atoi(tab[j]));
				if (!head)
				{
					head = new_node;
					current = head;
				}
				else
				{
					current->next = new_node;
					current = new_node;
				}
				j++;
			}
			ft_free_split(tab);
		}
		i++;
	}
	result.stack_a = head;
	return (result);
}
int run_strategy(t_strategy strat, t_stack **a, t_stack **b, int *op_counters)
{
	double disorder;
	int count;

	count = 0;
	disorder = disorder_metrics(*a);
	if (strat == STRAT_SIMPLE)
		count =  improved_simple_sort(a, b, op_counters);
	else if (strat == STRAT_MEDIUM)
		count =  medium_sort(a, b, op_counters);
	else if (strat == STRAT_COMPLEX)
		count = complex_sort(a, b, op_counters);
	else
		count = adaptive_sort(a, b, op_counters, disorder);
	return (count);
}
