/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 10:08:41 by lfabbian          #+#    #+#             */
/*   Updated: 2022/12/18 10:24:32 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *ft_strdup(char *src)
{
	char	*tmp;
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	tmp = malloc(sizeof(char) * len + 1);
	if (!tmp)
		return (NULL);
	while (src[i])
	{
		tmp[i] = src[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}
