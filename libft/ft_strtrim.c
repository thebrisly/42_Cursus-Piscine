/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:03:01 by lfabbian          #+#    #+#             */
/*   Updated: 2022/10/29 17:04:53 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

//retourne l'index initial (on saura si skip le premier mot ou non)
static int	ft_firstcheck(char const *s1, char const *set)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (set[i])
	{
		if (set[i] == s1[i])
			count++;
		i++;
	}
	if (count == (ft_strlen(set)))
		return (count);
	else
		return (0);
}

//retourne l'index final (pour savoir ou s'arrêter avec le while)
static int	ft_lastcheck(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	count;

	i = ft_strlen(s1) - 1;
	j = ft_strlen(set) - 1;
	count = 0;
	while (j >= 0)
	{
		if (set[j] == s1[i])
			count++;
		i--;
		j--;
	}
	if (count == (ft_strlen(set)))
		return (ft_strlen(s1) - ft_strlen(set));
	else
		return (ft_strlen(s1));
}

char *ft_strtrim(char const *s1, char const *set)
{
	char	*tab;
	int		i;
	int		j;
	int 	k;

	i = 0;
	tab = malloc(sizeof(char) * ft_strlen(s1));
	if (!tab)
		return (NULL);
	j = ft_firstcheck(s1, set);
	k = ft_lastcheck(s1, set);
	while (j < k)
	{
		tab[i] = s1[j];
		i++;
		j++;
	}
	tab[i] = '\0';
	return (tab);
}

/*int main()
{
    char *a;
    char    test1[] = "612346";
    char    set[] = "6";
    a = ft_strtrim(test1, set);
    printf("%s\n", a);
}*/
