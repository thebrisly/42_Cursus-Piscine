/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:38:00 by dferreir          #+#    #+#             */
/*   Updated: 2022/10/18 10:48:51 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (0);
	result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (0);
	while (s1[i])
	{
		result[j] = s1[i++];
		j++;
	}
	i = 0;
	while (s2[i])
	{
		result[j] = s2[i++];
		j++;
	}
	result[j] = '\0';
	return (result);
}

/*int	main()
{
	char s1[] = "Hello ";
	char s2[] = "World!";

	printf("%s", ft_strjoin(s1, s2));
	return 0;
}*/
