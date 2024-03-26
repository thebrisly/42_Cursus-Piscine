/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 10:59:47 by fgrasset          #+#    #+#             */
/*   Updated: 2022/11/07 13:02:29 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0 || src == (NULL))
		return ((size_t)ft_strlen(src));
	while (i < dstsize - 1 && (i < ft_strlen(src)))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return ((size_t)ft_strlen(src));
}
