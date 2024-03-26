/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:38:24 by dferreir          #+#    #+#             */
/*   Updated: 2022/10/18 11:07:44 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

/*int main()
{
	printf("%s\n", strchr("tripouille", 't' + 256));
	printf("%s\n", ft_strchr("tripouille", 't' + 256));

	return (0);
}*/
