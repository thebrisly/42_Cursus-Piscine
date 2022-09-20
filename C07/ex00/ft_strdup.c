/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:42:55 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/15 10:29:52 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	int		i_src;
	int		i_dest;
	char	*dest;

	i_src = 0;
	i_dest = 0;
	while (src[i_src])
		i_src++;
	dest = malloc((i_src + 1) * sizeof(char));
	if (!dest)
		return ("NULL");
	else
	{
		while (src[i_dest])
		{
			dest[i_dest] = src[i_dest];
			i_dest++;
		}
		dest[i_dest] = '\0';
		return (dest);
	}
}
/*
#include <string.h>
int	main()
{
	char chaine[] = "HEllo World"; 
	//printf("%s", strdup("Hello World"));
	printf("%s", ft_strdup(chaine));
}*/
