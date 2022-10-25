/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:04:04 by lfabbian          #+#    #+#             */
/*   Updated: 2022/10/25 13:16:01 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    int     i;
    int     len;
    char    *tab;

    i = 0;
    len = ft_strlen(s);
    tab = malloc(sizeof(char) * len)
    if (!= tab)
        return (NULL);
    while (s[i])
    {
        tab[i] = (*f)(i, s[i]);
        i++;
    }
    return (tab);
}