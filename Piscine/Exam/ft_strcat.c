/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:57:11 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/22 19:21:59 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return(dest);
}
#include <stdio.h>
int	main()
{
	char chaine[] = "is going to kill us";
	char chaine2[] = "bull run";

	printf("%s", ft_strcat(chaine2, chaine));
	//printf("%s", strcat(chaine2, chaine));
	return(0);
}
