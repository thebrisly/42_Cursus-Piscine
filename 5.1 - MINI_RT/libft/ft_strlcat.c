/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:40:05 by fgrasset          #+#    #+#             */
/*   Updated: 2022/11/07 12:57:19 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lendst;

	i = 0;
	lendst = 0;
	while (dst[lendst] && lendst < dstsize)
		lendst++;
	while (src[i] && (i + lendst + 1) < dstsize)
	{
		dst[i + lendst] = src[i];
		i++;
	}
	if (lendst != dstsize)
		dst[i + lendst] = '\0';
	return (ft_strlen(src) + lendst);
}
