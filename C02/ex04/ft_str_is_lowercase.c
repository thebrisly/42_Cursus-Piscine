/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:56:34 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/05 10:50:38 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((!(str[i] >= 'a' && str[i] <= 'z')))
			return (0);
		i++;
	}
	return (1);
}
/*int	main()
{
	char chaine[] = "42875328aA(";
	int i;

	i = ft_str_is_lowercase(chaine);
	printf("%d \n", i);
}*/
