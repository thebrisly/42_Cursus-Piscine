/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:07:36 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/07 18:47:14 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	ls;

	ls = 0;
	i = 0;
	while (*(src + ls) != '\0')
		ls++;
	if (size < 1)
		return (ls);
	while (i < size - 1 && src[i] != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	dest[i] = '\0';
	return (ls);
}
/*int	main()
{
	char	chaine[] = "hello";
	char	chaine2[] = "abc";
	int r;

	r = strlcpy(chaine2, chaine, 2);
	printf("Copied '%s' into '%s', length %d\n",chaine, chaine2, r);
	printf("%u\n", ft_strlcpy(chaine2, chaine, 2));
}*/
