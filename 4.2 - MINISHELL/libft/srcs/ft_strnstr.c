/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:09:08 by dferreir          #+#    #+#             */
/*   Updated: 2022/10/20 14:51:33 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] && needle[j] && haystack[i + j] == needle[j]
			&& (i + j) < len)
			j++;
		if (!needle[j])
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}

/*int main()
{
	char	hay[] = "aaabcabcd";
	char	nee[] = "aabc";

	printf("%s\n", strnstr(hay, nee, -1));
	printf("%s\n", ft_strnstr(hay, nee, -1));
	return (0);
}*/
