/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:40:15 by lfabbian          #+#    #+#             */
/*   Updated: 2022/11/02 09:40:19 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}



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
		if (s[i] != c && ok == 1)
		{
			ok = 0;
			count++;
		}
		else if (s[i] == c)
			ok = 1;
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
	while (start <= end)
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
	tab = malloc(sizeof(char) * (ft_number_of_words(s, c) + 1));
	if (!tab || !s)
		return (NULL);
	while (i_tab < ft_number_of_words(s, c))
	{
		while (s[i + j] == c)
			i++;
		j = i + 1;
		while (s[j] != c || s[j])
			j++;
		tab[i_tab] = ft_word_into_tab(s, i, j);
		i_tab++;
	}
	tab[i_tab] = 0;
	return (tab);
}

int main()
{
	int	i;
	const char	*s = "fgjgdg";
	char	c = 'g';
	char	**t = ft_split(s, c);

	i = 0;
	while (t[i])
	{
		printf("%s\n", t[i]);
		i++;
	}
}