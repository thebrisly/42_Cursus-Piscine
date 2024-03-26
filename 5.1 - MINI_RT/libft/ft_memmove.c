/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:54:55 by fgrasset          #+#    #+#             */
/*   Updated: 2022/11/07 13:01:37 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == (NULL) && src == (NULL))
		return (0);
	i = 0;
	if (dst > src)
	{
		while (len > 0)
		{
			*(unsigned char *)(dst + (len - 1)) = *(unsigned char *) \
			(src + (len - 1));
			len--;
		}
		return (dst);
	}
	while (i < len)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dst);
}
