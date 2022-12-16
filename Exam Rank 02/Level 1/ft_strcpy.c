/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:45:10 by lfabbian          #+#    #+#             */
/*   Updated: 2022/12/16 13:33:47 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strcpy(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = 0;
    return (s1);
}

/*#include <stdio.h>
int main()
{
    char    *hello;
    char    *dest;

    hello = "hello";
    printf("%s", ft_strcpy(dest, hello));
}*/
