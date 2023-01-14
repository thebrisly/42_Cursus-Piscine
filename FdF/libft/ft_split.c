/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:40:15 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/14 13:02:21 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		i_tab;

	i = 0;
	j = 0;
	i_tab = 0;
	tab = malloc(sizeof(char *) * (ft_number_of_words(s, c) + 1));
	if (!tab || !s)
		return (NULL);
	while (i_tab < ft_number_of_words(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[j] != c && s[j])
			j++;
		tab[i_tab] = ft_word_into_tab(s, i, j);
		i = j;
		i_tab++;
	}
	tab[i_tab] = 0;
	return (tab);
}
