/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:02:31 by lfabbian          #+#    #+#             */
/*   Updated: 2022/10/25 13:18:38 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    unsigned int i;
    char    *tab;

    i = 0;
    tab = malloc(sizeof(char) * (len));
    if (!tab)
        return (NULL);
    while (len > 0 && s[i])
    {
        tab[i] = s[start];
        len--;
    }
    return (tab);
}

/*int main()
{
    char    *a;
    char test1[] = "hello ca va";

    a = ft_substr(test1, 6, 5);
    printf("%s\n", a);
}*/