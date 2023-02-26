/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:43:46 by dferreir          #+#    #+#             */
/*   Updated: 2022/10/17 13:44:07 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		*(unsigned char *)(b + i++) = (unsigned char)c;
	return (b);
}

/*
int main()
{
   char str[] = "This is string.h library function";
   char str1[50];
   char str2[50];

   strcpy(str1,str);
   puts(str);

   memset(str1+2,'$',7);
   puts(str1);

   strcpy(str2, str);
   ft_memset(str2+2,'$',7);
   puts(str2);

   return (0);
}*/
