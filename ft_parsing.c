/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaobe <arajaobe@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 16:52:51 by samrazaf          #+#    #+#             */
/*   Updated: 2026/03/25 14:41:14 by arajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	check_flags(char *str)
{
	if ((!ft_strcmp(str, "--simple")) ||
	(!ft_strcmp(str, "--medium")) ||
	(!ft_strcmp(str, "--complex")) ||
	(!ft_strcmp(str, "--adaptive")))
		return (0);
	return (1);
}

int check_flags_bench(char *str)
{
	if (!ft_strcmp(str, "--bench"))
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

int checks_flags_position_double(int argc, char **argv)
{
	if (((!check_flags(argv[1]) && !check_flags_bench(argv[2])) && check_flags(argv[argc - 1]) && check_flags_bench(argv[argc - 2])) ||
		((!check_flags(argv[2]) && !check_flags_bench(argv[1])) && check_flags(argv[argc - 2]) && check_flags_bench(argv[argc - 1])) ||
		((!check_flags(argv[1]) && !check_flags_bench(argv[2])) && check_flags(argv[argc - 2]) && check_flags_bench(argv[argc - 1])) ||
		((!check_flags(argv[2]) && !check_flags_bench(argv[1])) && check_flags(argv[argc - 1]) && check_flags_bench(argv[argc - 2])))
		return (1);
	else if (((check_flags(argv[1]) && check_flags_bench(argv[2])) && !check_flags(argv[argc - 1]) && !check_flags_bench(argv[argc - 2])) ||
			((check_flags(argv[2]) && check_flags_bench(argv[1])) && !check_flags(argv[argc - 2]) && !check_flags_bench(argv[argc - 1])) ||
			((check_flags(argv[1]) && check_flags_bench(argv[2])) && !check_flags(argv[argc - 2]) && !check_flags_bench(argv[argc - 1])) ||
			((check_flags(argv[2]) && check_flags_bench(argv[1])) && !check_flags(argv[argc - 1]) && !check_flags_bench(argv[argc - 2])))
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
			if (!ft_isdigit(argv[j][i]) && argv[j][i] != ' ' &&  argv[j][i] != '-' && argv[j][i] != '+')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	check_argv_double(int argc, char **argv)
{
	int	i;
	int	j;

	if (!checks_flags_position_double(argc, argv))
		return (0);
	else if (checks_flags_position_double(argc, argv) == 1)
		j = 3;
	else
	{
		j = 1;
		argc = argc - 2;
	}
	while (j < argc)
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			if (!ft_isdigit(argv[j][i]) && argv[j][i] != ' ' &&  argv[j][i] != '-' && argv[j][i] != '+')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	check_argv_adaptive(int position, char **argv)
{
	if (!ft_strcmp(argv[position], "--adaptive"))
		return (1);
	return (0);
}

int check_bench(int position, char **argv)
{
	if (!ft_strcmp(argv[position], "--bench"))
		return (1);
	return (0);
}

int	use_fonction(t_stack **a, t_stack **b, int *op_operation, char **argv)
{
	int	i;
	int	count;
	int check;

	i = 1;
	check = 0;
	count = 0;
	while (argv[i])
	{
		if (!ft_strcmp(argv[i], "--simple"))
			check = 1;
		else if (!ft_strcmp(argv[i], "--medium"))
			check = 2;
		else if (!ft_strcmp(argv[i], "--complex"))
			check = 3;
		i++;
	}
	if (check == 1)
		count = improved_simple_sort(a, b, op_operation);
	else if (check == 2)
		count = medium_sort(a, b, op_operation);
	else if (check == 3)
		count = complex_sort(a, b, op_operation);
	return (count);
}

int	use_adaptive_fonction(t_stack **a, t_stack **b, int *op_operation, double disorder)
{
	int		count;

	count = 0;
	if (disorder < 0.2)
	{
		count = improved_simple_sort(a, b, op_operation);
		ft_printf(2, "simple");
	}
	else if (disorder >= 0.2 && disorder < 0.5)
	{
		count = medium_sort(a, b, op_operation);
		ft_printf(2, "medium");
	}
	else
	{
		count = complex_sort(a, b, op_operation);
		ft_printf(2, "complex");
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

	if (argc <= 1 || !check_argv(argc, argv))
	{
		ft_printf(2, "error\n");
		exit(1);
		return NULL;
	}
	if (check_flags_position(argc, argv) == 1)
		i = 2;
	//else if (checks_flags_position_double(argc, argv) == 1)
	//	i = 3;
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


t_stack	*list_arg_fillers_double(int argc, char **argv)
{
	t_stack *head;
	t_stack	*current;
	t_stack	*new_node;
	int		i;
	int		j;
	char	**tab;

	if (argc <= 1 || !check_argv_double(argc, argv))
	{
		ft_printf(2, "error\n");
		exit(1);
		return NULL;
	}
	if (checks_flags_position_double(argc, argv) == 1)
		i = 3;
	else if (checks_flags_position_double(argc, argv) > 1)
	{
		i = 1;
		argc = argc - 2;
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


static	int	count_words(const char *str, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static	char	**free_tab(char **tab, int j)
{
	while (j >= 0)
	{
		free(tab[j]);
		j--;
	}
	free (tab);
	return (NULL);
}

static	int	word_len(const char *str, char c)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != c)
	{
		len++;
	}
	return (len);
}

static	char	**sub_split(char **tab, char const *s, char c)
{
	int		i;
	int		len;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			len = word_len(&s[i], c);
			tab[j] = ft_substr(s, i, len);
			if (!tab[j])
			{
				free_tab(tab, j - 1);
				return (NULL);
			}
			i += len;
			j++;
		}
		else
			i++;
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char	const *s, char c)
{
	char	**tab;
	size_t	word;
	char	**result;

	word = count_words(s, c);
	tab = (char **)malloc(sizeof(char *) * (word + 1));
	if (!tab)
		return (NULL);
	if (!s)
		return (NULL);
	result = sub_split(tab, s, c);
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
		i++;
	j = 0;
	while (j <= i)
	{
		if ((unsigned char)s[j] == (unsigned char)c)
			return ((char *)&s[j]);
		j ++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[j]);
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i ++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i ++;
	}
	return (i);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= (size_t)start)
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i++] = s[start++];
	}
	ptr[i] = '\0';
	return (ptr);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
