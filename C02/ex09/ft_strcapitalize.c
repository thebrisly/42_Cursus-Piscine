/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:25:06 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/07 19:17:26 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if ((*(str + i) >= 'A' && *(str + i) <= 'Z'))
			*(str + i) = *(str + i) + 32;
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z') && ((str[i - 1] >= 0
					&& str[i - 1] < 48) || (str[i - 1] >= 58 && str[i -1] < 65)
				|| (str[i - 1] >= 91 && str[i -1] < 97)
				|| (str[i - 1] > 122)))
			*(str + i) = *(str + i) - 32;
	i++;
	}
	return (str);
}
/*int	main()
{
	char chaine[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	
	printf("%s \n", ft_strcapitalize(chaine));
}*/
