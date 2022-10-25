/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:04:57 by lfabbian          #+#    #+#             */
/*   Updated: 2022/10/25 14:27:08 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
    char    *tab;
    int     i;
    int     count;

    i = 0;
    count = 0;
    tab = malloc(sizeof(char) * /*TAILLE*/ );
    if (!tab)
        return (NULL);
    return (tab);
    while (s1[i] == set[i] && s1[i])
        i++;
    while (s1[ft_strlen(s1) - 1] == set[ft_strlen(set) - 1])
    {
        count+=1;
        *s1--;
        *set--;
    }
    while (i < ft_strlen(s1) - count)
    {
        tab[i] == s1[i];
        i++;
    }
    return (tab);
}