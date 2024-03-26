/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:45:55 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/07 11:53:41 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
/*int	main()
{
	char chaine1[] = "1234_z";
	char chaine2[] = "1234adhf";

	printf("%d\n", ft_strcmp(chaine1, chaine2));
	printf("%d\n", strcmp(chaine1, chaine2));
}*/
