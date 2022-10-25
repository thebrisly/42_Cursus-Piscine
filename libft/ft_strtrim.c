/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:04:57 by lfabbian          #+#    #+#             */
/*   Updated: 2022/10/25 12:58:18 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
    char    *tab;
    int     i;
    int     j;
    int     len_str;
    int     len_set;

    len_str = ft_strlen(s1);
    len_set = ft_strlen(set);
    tab = malloc(sizeof(char) * (len_str - (2*len_set)))
    if (!tab)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        j = 0;
        while (set[j] && i > (len_str + len_set) - 2)
        {
            if (s1[i] ==0 set [j])
                i++;
            j++;
        }
        *tab = s1[i];
        i++
        *tab++;
    }
    return (tab);
}