/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:50:35 by dferreir          #+#    #+#             */
/*   Updated: 2022/10/24 11:26:19 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_counter(const char *s, char c)
{
	int	nb_words;
	int	swtch;

	nb_words = 0;
	swtch = 0;
	while (*s)
	{
		if (*s != c && swtch == 0)
		{
			nb_words++;
			swtch = 1;
		}
		if (*s++ == c && swtch == 1)
			swtch = 0;
	}
	return (nb_words);
}

char	*str_maker(const char *s, int start, int end)
{
	char	*new_s;
	size_t	i;

	i = 0;
	new_s = malloc((end - start + 1) * sizeof(char));
	while (start < end)
		new_s[i++] = s[start++];
	new_s[i] = 0;
	return (new_s);
}

char	**ft_split(char const *s, char c)
{
	char	**new_strs;
	size_t	i;
	size_t	j;
	int		start;

	i = 0;
	j = 0;
	start = -42;
	new_strs = malloc((word_counter(s, c) + 1) * sizeof(char *));
	if (!s || !new_strs)
		return (0);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || !s[i]) && start >= 0)
		{
			new_strs[j++] = str_maker(s, start, i);
			start = -42;
		}
		i++;
	}
	new_strs[j] = 0;
	return (new_strs);
}

/*int main()
{
	char s[] = "hello!";
	char c = ' ';

	printf("%s\n", ft_split(s, c)[0]);
	printf("%s\n", ft_split(s, c)[1]);
	printf("%s", ft_split(s, c)[2]);

	return 0;
}*/
