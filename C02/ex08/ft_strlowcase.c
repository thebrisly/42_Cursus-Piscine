/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 00:42:43 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/05 11:01:42 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char*str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if ((*(str + i) >= 'A' && *(str + i) <= 'Z'))
		{
			*(str + i) = *(str + i) + 32;
		}
		else
			*(str + i) = *(str + i);
	i++;
	}
	return (str);
}
/*int	main()
{
	char chaine[] = "HELLO COMmENT TU VAs";

	printf("%s \n", ft_strlowcase(chaine));
}*/
