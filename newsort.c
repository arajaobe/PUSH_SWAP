
int new_sort(t_stack **a, t_stack **b)
{
	int temp;
	t_stack *x;
	t_stack *y;

	x = *a;
	while (*a)
	{
		temp = find_content(*a, 1);
		while (*b && find_content(*b, 1) > find_content(*a, 1))
		{
			pa(a,b);
			sa(a);
		}
		pb(a,b);
	}
}
