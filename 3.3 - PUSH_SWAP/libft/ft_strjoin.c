/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:39:27 by brisly            #+#    #+#             */
/*   Updated: 2022/11/01 17:22:16 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	tab = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!tab)
		return (NULL);
	while (s1[i])
		tab[j++] = s1[i++];
	i = 0;
	while (s2[i])
		tab[j++] = s2[i++];
	return (tab);
}

/*int	main()
{
	char 	*s1 = "my favourite animal is";
	char	*s2 = " ";
	char	*s3 = "the nyancat";
	char	*res;
	res = ft_strjoin(ft_strjoin(s1, s2), s3);
	printf("%s", res);
}*/
