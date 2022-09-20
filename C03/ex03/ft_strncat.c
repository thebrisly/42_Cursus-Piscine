/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 09:33:27 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/06 16:26:11 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	is;
	unsigned int	id;

	is = 0;
	id = 0;
	while (dest[id] != '\0')
		id++;
	while (src[is] != '\0' && is < nb)
	{
		dest[id] = src[is];
		is++;
		id ++;
	}
	dest[id] = '\0';
	return (dest);
}
/*int	main()
{
	char chaine[] = ", add this";
	char chaine2[] = "This is my initial string";

	printf("%s", ft_strncat(chaine2, chaine, 5));
	//printf("%s\n", strncat(chaine2, chaine, 5));
	return(0);
}*/
