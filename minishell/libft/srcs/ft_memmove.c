/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:52:22 by dferreir          #+#    #+#             */
/*   Updated: 2022/10/20 14:35:32 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	if ((size_t)dst - (size_t)src < len)
	{
		i = len - 1;
		while (i < len)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dst);
}

/*int main () {
   const char src[]  = "Hello";
   char dest[] = "Hell";
   char dest2[] = "Hell";

   printf("Before memmove dest = %s, src = %s\n", dest, src);
   printf("Before memmove dest = %s, src = %s 2\n", dest2, src);
   memmove(dest, src, 6);
   ft_memmove(dest2, src, 6);
   printf("After memmove dest = %s, src = %s\n", dest, src);
   printf("After memmove dest = %s, src = %s 2\n", dest2, src);

   return(0);
}*/
