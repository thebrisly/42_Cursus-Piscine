/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:41:20 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/22 18:24:18 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (str[i + j] == to_find[j])
			{
				j++;
				if (to_find[j] == '\0')
					return(&str[i]);
			}
		}
		i++;
	}
	return (0);
}
#include <stdio.h>
int	main()
{	
	char chaine1[] = "Hello arhow are345 you?";
	char chaine2[] = "are";
	char *ptr;

	ptr = ft_strstr(chaine1, chaine2);
	printf("%s\n", ptr);
	printf("%s\n", ft_strstr(chaine1, chaine2));
}
