/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:58:43 by brisly            #+#    #+#             */
/*   Updated: 2022/10/24 15:09:09 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
       unsigned char *dest1;
       unsigned char *src1;

       dest1 = (unsigned char *)dest;
       src1 = (unsigned char *)src;
       if (dest1 && src1)
       {
              while (n > 0)
              {
                     *dest1++ = *src1++;
                     n--;
              }
       }
       return (dest);
}

/* DESCRIPTION
       The  memcpy()  function  copies  n bytes from memory area src to memory area dest.  The memory areas must not overlap.  
       Use memmove(3) if the memory areas do overlap.

RETURN VALUE
       The memcpy() function returns a pointer to dest.*/

/* A TESTER JSP SI C'EST JUSTE !*/