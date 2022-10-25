/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:00:09 by brisly            #+#    #+#             */
/*   Updated: 2022/10/20 13:57:11 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t  len;
    size_t  i;

    len = 0;
    while (dst[len] != '\0' && len < size)
        len++;
    i = len;
}

/* strlcat() appends string src to the end of dst. 
It will append at most dstsize – strlen(dst) – 1 characters. 
It will then NUL-terminate, unless dstsize is 0 or the original 
dst string was longer than dstsize (in practice this should 
not happen as it means that either dstsize is incorrect 
or that dst is not a proper string). */