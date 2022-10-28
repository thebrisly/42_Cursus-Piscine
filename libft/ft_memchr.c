/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:59:20 by brisly            #+#    #+#             */
/*   Updated: 2022/10/28 10:41:09 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*s1;
	unsigned int	i;

	s1 = (char *) s;
	i = 0;
	while (n > i)
	{
		if (s1[i] == (unsigned char) c)
			return ((void *) &s1[i]);
		i++;
	}
	return (NULL);
}
