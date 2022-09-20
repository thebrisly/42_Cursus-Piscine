/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 23:55:03 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/06 16:10:27 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src)
{
	int	is;
	int	id;

	is = 0;
	id = 0;
	while (dest[id] != '\0')
		id++;
	while (src[is] != '\0')
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
	char chaine[] = "is going to kill us";
	char chaine2[] = "";

	printf("%s", ft_strcat(chaine2, chaine));
	//printf("%s", strcat(chaine2, chaine));
	return(0);
}*/
