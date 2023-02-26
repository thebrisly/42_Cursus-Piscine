/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:13:38 by dferreir          #+#    #+#             */
/*   Updated: 2022/10/17 13:20:38 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		*(char *)(s + i++) = 0;
}

/*
int main()
{
	char str[] = "Bonjour";
	char str1[50];
	char str2[50];

	strcpy(str1, str);
	puts(str);

	bzero(str1+2, 3);
	puts(str1);

	strcpy(str2, str);
	ft_bzero(str2+2, 3);
	puts(str2);

	return (0);
}*/
