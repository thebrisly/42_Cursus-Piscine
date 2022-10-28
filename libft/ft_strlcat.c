/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:00:09 by brisly            #+#    #+#             */
/*   Updated: 2022/10/28 13:53:41 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(dst);
	if (dstsize < len)
		return (ft_strlen(src) + dstsize);
	while (i < dstsize - len)
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[dstsize - 1] = '\0';
	return (ft_strlen(src) + len);
}

/*int main()
{
    char dst[] = "abcd";
    char src[] = "efgh";

    printf("%zu\n", ft_strlcat(dst, src, 2));
    printf("%zu\n", strlcat(dst, src, 2));
}*/

/* strlcat() appends string src to the end of dst. 
It will append at most dstsize – strlen(dst) – 1 characters. 
It will then NUL-terminate, unless dstsize is 0 or the original 
dst string was longer than dstsize (in practice this should 
not happen as it means that either dstsize is incorrect 
or that dst is not a proper string). */