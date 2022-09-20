/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 23:11:23 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/07 17:01:27 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] != '\0' || s2[i] != '\0') && (i < n -1) && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
/*int	main()
{
	char chaine[] = "ijie";
	char chaine2[] = "";

	printf("%d\n", strncmp(chaine, chaine2, 0));
	printf("%d\n", ft_strncmp(chaine, chaine2, 0));
}*/
