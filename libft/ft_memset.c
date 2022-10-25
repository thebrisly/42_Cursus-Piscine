/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:28:33 by brisly            #+#    #+#             */
/*   Updated: 2022/10/20 13:57:03 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memset(void *s, int c, size_t n)
{
    unsigned char    *s1;

    s1 = (char *) s;
    while (n > 0)
    {
        *(s1) = (unsigned char) c;
        *(s1++);
        n--;
    }
    return (s);
}


// PK DES GENS ONT PAS LE MEME MODELE ???????? a la place de s ils ont b et a la place de n "len" mdr niquez vous


/* DESCRIPTION
       The memset() function fills the first n bytes of the memory area pointed to by s with the constant byte c.

RETURN VALUE
       The memset() function returns a pointer to the memory area s.*/