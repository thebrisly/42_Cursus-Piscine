/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:03:01 by lfabbian          #+#    #+#             */
/*   Updated: 2022/11/02 15:36:06 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_issep(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_startinit(int i, char const *s1, char const *set)
{
	while (ft_issep(s1[i], set))
		i++;
	return (i);
}

static int	ft_endinit(int j, char const *s1, char const *set)
{
	if (j < 0)
		j = 0;
	while (ft_issep(s1[j], set))
		j--;
	return (j);
}

static int	ft_strlen1(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tab;
	int		i;
	int		j;
	int		k;

	i = ft_startinit(0, s1, set);
	j = ft_endinit(ft_strlen(s1) - 1, s1, set);
	k = 0;
	if (i >= ft_strlen1(s1))
		return (ft_strdup(""));
	tab = malloc(sizeof(char) * ((j - i) + 2));
	if (!tab || !s1)
		return (NULL);
	while (i <= j)
	{
		tab[k] = s1[i];
		k++;
		i++;
	}
	tab[k] = '\0';
	return (tab);
}
