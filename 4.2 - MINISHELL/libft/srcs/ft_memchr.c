/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:56:54 by dferreir          #+#    #+#             */
/*   Updated: 2022/10/18 11:40:56 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}

/*int	main()
{
	const void *str = "arbre";
	char chr = 'r';
	int len = 5;

	printf("%s\n", memchr(str, chr, len));
	printf("%s", ft_memchr(str, chr, len));

	return (0);
}*/
