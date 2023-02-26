/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:21:37 by dferreir          #+#    #+#             */
/*   Updated: 2022/10/18 11:08:18 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	s--;
	while (i-- >= 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
	}
	return (0);
}

/*int main()
{
	printf("%s\n", strrchr("arbre", '\0'));
	printf("%s\n", ft_strrchr("arbre", '\0'));

	return (0);
}*/
