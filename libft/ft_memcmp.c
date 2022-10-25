/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:33:30 by brisly            #+#    #+#             */
/*   Updated: 2022/10/20 13:56:59 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned char   ss1;
    unsigned char   ss2;

    ss1 = (char *) s1;
    ss2 = (char *) s2;
    if (n <= 0)
        return (0);
    while (n > 0 && *ss1 == *ss2)
    {
        n--;
        ss1++;
        ss2++;
    }
    return ((int)(*ss1 - *ss2));
}/*


/*DESCRIPTION
       The memcmp() function compares the first n bytes (each interpreted as unsigned char) of the memory areas s1 and s2.

RETURN VALUE
       The  memcmp()  function  returns  an integer less than, equal to, or greater than zero if the first n bytes of s1 is found, 
       respectively, to be less than, to match, or be greater than the first n bytes of s2.

       For a nonzero return value, the sign is determined by the sign of the difference between the first pair of bytes 
       (interpreted as unsigned char)  that  differ in s1 and s2.

       If n is zero, the return value is zero.*/