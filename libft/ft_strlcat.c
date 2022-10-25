/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:00:09 by brisly            #+#    #+#             */
/*   Updated: 2022/10/25 16:37:26 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t i;
    size_t j;
    size_t len_dest;

    i = 0;
    j = 0;
    len_dest = ft_strlen(dst);
    while (dst[i] && i < dstsize)
    {
        i++;
    }
    while (src[j] && i < dstsize - 1)
    {
        dst[i++] = src[j++];
    }
    if (dstsize != 0 && dstsize >= len_dest)
        dst[i] = '\0';
    if (dstsize < ft_strlen(dst))
        return (ft_strlen(src) + dstsize);
    else
        return (ft_strlen(src) + len_dest);
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