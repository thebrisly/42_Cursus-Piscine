/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:28:12 by dferreir          #+#    #+#             */
/*   Updated: 2022/10/20 14:01:51 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	acc;

	acc = 0;
	if (!dst && !src)
		return (0);
	while (acc < n)
	{
		*(char *)(dst + acc) = *(char *)(src + acc);
		++acc;
	}
	return (dst);
}

/*
int main()
{
   const char src[50] = "http://www.tutorialspoint.com";
   char dest[50];
   char dest2[50];

   strcpy(dest,"Heloooo!!");
   printf("Before memcpy dest = %s\n", dest);
   strcpy(dest2,"Heloooo!!");
   printf("Before memcpy dest = %s 2\n", dest2);
   memcpy(dest, src, strlen(src)+1);
   printf("After memcpy dest = %s\n", dest);
   ft_memcpy(dest2, src, strlen(src)+1);
   printf("After memcpy dest = %s 2\n", dest2);

   return (0);
}*/
