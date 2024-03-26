/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:56:55 by fgrasset          #+#    #+#             */
/*   Updated: 2022/11/07 13:03:02 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	int		i;

	i = 0;
	if (start >= ft_strlen(s))
		len = 0;
	if ((ft_strlen(s) - start) < len)
		len = ft_strlen(s) - start;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == (NULL))
		return (NULL);
	while (len > 0)
	{
		ptr[i] = s[start + i];
		i++;
		len --;
	}
	ptr[i] = '\0';
	return (ptr);
}
