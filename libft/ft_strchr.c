/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:31:50 by brisly            #+#    #+#             */
/*   Updated: 2022/10/20 13:57:08 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strchr(const char *s, int c)
{
    unsigned int i;

    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
            return ((char *)&s[i]);
        i++;
    }
    if (s[i] == c)
        return ((char *) &s[i]);
    return (NULL);
}

/*#include <stdio.h>
int main()
{
    char a[] = "http://www.tutorialspoint.com";
    printf("%s\n", ft_strchr(a, 's'));
}*/