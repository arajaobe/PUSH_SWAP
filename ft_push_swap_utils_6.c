
#include "ft_push_swap.h"

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
void ft_free_split(char **split)
{
	int i = 0;

	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
int is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return 0;
		stack = stack->next;
	}
	return (1);
}
int bit_count(int max_index)
{
	int bits = 0;

	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}
