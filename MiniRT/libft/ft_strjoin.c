/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:56:45 by fgrasset          #+#    #+#             */
/*   Updated: 2022/11/07 13:02:20 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*ptr;

	i = -1;
	ptr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s1[++i])
		ptr[i] = s1[i];
	i--;
	while (s2[++i - ft_strlen(s1)])
		ptr[i] = s2[i - ft_strlen(s1)];
	ptr[i] = '\0';
	return (ptr);
}
