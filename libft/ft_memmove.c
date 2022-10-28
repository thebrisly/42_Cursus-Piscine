/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 23:23:07 by brisly            #+#    #+#             */
/*   Updated: 2022/10/28 14:55:34 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest1;
	unsigned char	*src1;

	dest1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	if (dest1 && src1)
	{
		if (src1 < dest1)
		{
			while (len > 0)
			{
				dest1[len] = src1[len];
				len--;
			}
		}
		else
		{
			while (len > 0)
			{
				*dest1++ = *src1++;
				len--;
			}
		}
	}
	return (dst);
}
