/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:57:08 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/06 20:23:07 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
/*int	main()
{
	char	chaine[] = "";
	int	nombre;
	
	nombre = 0;
	nombre = ft_strlen(chaine);
	printf("Voici le nombre de lettre que posse le mot: %d", nombre);
}*/
