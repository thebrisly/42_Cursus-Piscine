/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 23:23:07 by brisly            #+#    #+#             */
/*   Updated: 2022/10/22 18:36:30 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
    unsigned char *dest1;
    unsigned char *src1;

    dest1 = (unsigned char *)dst;
    src1 = (unsigned char *)src;
    if (dest1 && src1)
    {
        if (src1 < dest1)
        {
            while (len > 0)
            {
                dest1[len] = src1[len];
                len--; 
            }
        }
        else
        {
            while (len > 0)
            {
                *dest1++ = *src1++;
                len--;
            }
        }
    }
    return (dst);
}

/*As discussed earlier, the memmove() function in C Programming can move the content
 from the source location to the destination buffer even if both buffers overlap (chevauchent).
If it is given that the source and destination are not overlapping (chevauchement) with each other,
then it is advised to use memcpy() instead of the memmove() function. 
But if they are overlapping, then the function will show undefined behavior.
In that case, you should use the memmove() function.*/

/*The memmove() function copies n bytes from memory area src to memory area dest.  
The memory areas may overlap: copying takes place as though the bytes in src are first
copied into a temporary array that does not overlap src or dest, and the bytes are then 
copied from the temporary array to dest.*/