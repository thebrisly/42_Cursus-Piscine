/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:28:33 by brisly            #+#    #+#             */
/*   Updated: 2022/10/29 11:34:53 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s1;
	size_t			i;

	i = 0;
	s1 = (unsigned char *) b;
	while (len > i)
	{
		s1[i] = (unsigned char) c;
		i++;
	}
	return (b);
}

/* DESCRIPTION
       The memset() function fills the first n bytes of the memory area pointed to by s with the constant byte c.

RETURN VALUE
       The memset() function returns a pointer to the memory area s.*/