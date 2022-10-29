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

char *ft_strtrim(char const *s1, char const *set)
{
	char	*tab;
	int		count;
	int		i;

	count = 0;
	j = 0;
	tab = ft_calloc(sizeof(char), ft_strlen(s1));
	if (!tab)
		return (NULL);
	while (set[i])
	{
		if (s1[i] == set[i])
			count++;
	}
	if (count == ft_strlen(set))

	
}

/*int main()
{
    char *a;

    char    test1[] = "arghearglloarg";
    char    set[] = "arg";
    a = ft_strtrim(test1, set);
    printf("%s\n", a);
}*/

/*
    char    *tab;
    int     i;
    int     count;
    int     end_s1;
    int     end_set;

    i = 0;
    end_s1 = ft_strlen(s1) - 1;
    end_set = ft_strlen(set) - 1;
    count = 0;
    tab = malloc(sizeof(char) * (ft_strlen(s1) + 1));
    if (!tab)
        return (NULL);
    while (s1[i] == set[i] && s1[i])
        i++;
    while (s1[end_s1] == set[end_set])
    {
        count+=1;
        end_s1--;
        end_set--;
    }
    while (i <= end_s1)
    {
        tab[i] = s1[i];
        i++;
    }
    tab[i] = 0;
    return (tab);*/