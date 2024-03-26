/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:40:15 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/22 15:56:16 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_split {
	char	**tab;
	int		i;
	int		j;
	int		i_tab;
}	t_split;

static int	ft_number_of_words(char const *s, char c)
{
	int	i;
	int	count;
	int	ok;

	i = 0;
	count = 0;
	ok = 0;
	while (s[i])
	{
		if (s[i] != c && ok == 0)
		{
			ok = 1;
			count++;
		}
		else if (s[i] == c)
			ok = 0;
		i++;
	}
	return (count);
}

static char	*ft_word_into_tab(char const *s, int start, int end)
{
	int		i;
	char	*tab_string;

	i = 0;
	tab_string = malloc(sizeof(char) * (end - start + 1));
	if (!tab_string)
		return (NULL);
	while (start < end)
	{
		tab_string[i] = s[start];
		start++;
		i++;
	}
	tab_string[i] = '\0';
	return (tab_string);
}

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	t_split	split;

	split.i = 0;
	split.j = 0;
	split.i_tab = 0;
	split.tab = malloc(sizeof(char *) * (ft_number_of_words(s, c) + 1));
	if (!split.tab || !s)
		return (NULL);
	while (split.i_tab < ft_number_of_words(s, c))
	{
		while (s[split.i] == c && s[split.i])
			split.i++;
		split.j = split.i;
		while (s[split.j] != c && s[split.j])
			split.j++;
		split.tab[split.i_tab] = ft_word_into_tab(s, split.i, split.j);
		if (!(split.tab[split.i_tab]))
			return (ft_free(split.tab, split.j));
		split.i = split.j;
		split.i_tab++;
	}
	split.tab[split.i_tab] = 0;
	return (split.tab);
}
