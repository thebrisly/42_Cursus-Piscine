/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:05:42 by fgrasset          #+#    #+#             */
/*   Updated: 2022/11/07 13:02:02 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (i < ((int)ft_strlen(s) + 1))
	{
		if (((char *) s)[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	return (NULL);
}
