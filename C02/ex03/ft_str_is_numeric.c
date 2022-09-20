/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:59:16 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/05 10:47:21 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9' ))
			return (0);
		i++;
	}
	return (1);
}

/*int	main()
{
	char chaine[] = "";
	int i;

	i = ft_str_is_numeric(chaine);
	printf("%d \n", i);
}*/
