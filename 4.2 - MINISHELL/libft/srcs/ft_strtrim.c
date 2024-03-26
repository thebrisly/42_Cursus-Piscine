/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:57:26 by dferreir          #+#    #+#             */
/*   Updated: 2022/10/18 16:09:16 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (*s1 && ft_strchr(set, s1[i - 1]))
		i--;
	return (ft_substr(s1, 0, i));
}

/*int main()
{
	char s1[] = "hello yeh";
	char s2[] = "he";

	printf("%s", ft_strtrim(s1, s2));
	return (0);
}*/
