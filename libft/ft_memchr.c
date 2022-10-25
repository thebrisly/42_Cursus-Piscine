/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:59:20 by brisly            #+#    #+#             */
/*   Updated: 2022/10/20 13:56:55 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memchr(const void *s, int c, size_t n)
{
    char            *s1;
    unsigned int    i;

    s1 = (char *) s;
    i = 0;
    while (n > i)
    {
        if (s1[i] == (unsigned char) c)
            return ((void *) &s1[i]);
        i++;
    }
    return (NULL);    
}

/*The  memchr()  function  scans  the  initial n bytes of the memory area pointed to by s for the first instance of c.  
Both c and the bytes of the memory area pointed to by s are interpreted as unsigned char.

The memchr() and memrchr() functions return a pointer to the matching byte or NULL if the character does not occur in the given memory area.*/