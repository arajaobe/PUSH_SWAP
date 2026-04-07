/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils_8.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samrazaf <samrazaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 16:52:51 by samrazaf          #+#    #+#             */
/*   Updated: 2026/04/07 19:00:32 by samrazaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

static int	count_words(const char *str, char c)
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

static char	**free_tab(char **tab, int j)
{
	while (j >= 0)
	{
		free(tab[j]);
		j--;
	}
	free (tab);
	return (NULL);
}

static int	word_len(const char *str, char c)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != c)
	{
		len++;
	}
	return (len);
}

static char	**sub_split(char **tab, char const *s, char c)
{
	int	i;
	int	len;
	int	j;

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

char	**ft_split(char const *s, char c)
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
