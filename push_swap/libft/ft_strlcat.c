/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:00:09 by brisly            #+#    #+#             */
/*   Updated: 2022/10/29 13:45:11 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(dst);
	if (dstsize <= len)
		return (ft_strlen(src) + dstsize);
	while (src[i] && len + 1 < dstsize)
	{
		dst[len] = src[i];
		i++;
		len++;
	}
	dst[len] = '\0';
	return (ft_strlen(&src[i]) + len);
}

/*int main()
{
    printf("%zu\n", ft_strlcat("pqrs", "abcdefghi", 16));
    printf("%zu\n", strlcat("pqrs", "abcdefghi", 16));
}*/

/* strlcat() appends string src to the end of dst. 
It will append at most dstsize – strlen(dst) – 1 characters. 
It will then NUL-terminate, unless dstsize is 0 or the original 
dst string was longer than dstsize (in practice this should 
not happen as it means that either dstsize is incorrect 
or that dst is not a proper string). */
