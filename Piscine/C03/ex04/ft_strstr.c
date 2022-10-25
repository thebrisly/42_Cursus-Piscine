/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:54:07 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/07 16:53:57 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	is;
	int	id;

	is = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[is] != '\0')
	{
		id = 0;
		if (str[is] == to_find[id])
		{
			while (str[is + id] == to_find[id])
			{
				id++;
				if (to_find[id] == '\0')
					return (&str[is]);
			}
		}
		is++;
	}
	return (0);
}
/*int	main()
{	
	char chaine1[] = "Hello arhow are345 you?";
	char chaine2[] = "are";
	char *ptr;

	ptr = strstr(chaine1, chaine2);
	printf("%s\n", ptr);
	printf("%s\n", ft_strstr(chaine1, chaine2));
}*/
