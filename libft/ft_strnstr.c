/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:29:39 by brisly            #+#    #+#             */
/*   Updated: 2022/10/24 15:21:44 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strnstr(const char *s1, const char *s2, size_t n)
{
    int i;
    int j;

    i = 0;
    if (s2[0] == '\0')
        return (s1);
    while (s1[i] != '\0' && i < n)
    {
        j = 0;
        if (s1[i] == s2[j])
        {
            while (s1[i + j] == s2[j] && (i + j) < n)
            {
                j++;
                if (s1[j] == '\0')
                    return (&s1[i])
            }
        }
        i++;       
    }
    return(0);
}

int main()
{
    char a[] = "http://www.tutorialspoint.com";
    char b[] = "ria";
    printf("%d\n", strnstr(a, b, 5));
}



/*The strnstr() function locates the first occurrence of the null-terminated
 string s2 in the string s1, where not more than n characters are searched.
Characters that appear after a `\0' character are not searched. */