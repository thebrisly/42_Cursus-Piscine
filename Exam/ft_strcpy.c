/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:41:02 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/19 15:51:12 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strcpy(char *s1, char *s2)
{
	int i;
	
	i = 0;
	while(s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return(s1);
}

#include <stdio.h>
int main()
{
	char *src = "hello";
	char *dest[100];

	printf("%s", ft_strcpy(dest, src));
}
