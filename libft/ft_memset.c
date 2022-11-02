/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:28:33 by brisly            #+#    #+#             */
/*   Updated: 2022/11/01 10:21:58 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s1;
	size_t			i;

	i = 0;
	s1 = (unsigned char *) b;
	while (len > i)
	{
		s1[i] = (unsigned char) c;
		i++;
	}
	return (b);
}
