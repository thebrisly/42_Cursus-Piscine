/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 00:27:43 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/05 10:58:31 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strupcase(char*str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if ((*(str + i) >= 'a' && *(str + i) <= 'z'))
		{
			*(str + i) = *(str + i) - 32;
		}
		else
			*(str + i) = *(str + i);
	i++;
	}
	return (str);
}
/*int	main()
{
	char chaine[] = "salut Ca vA";

	printf("%s \n", ft_strupcase(chaine));
}*/
