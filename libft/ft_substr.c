/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:02:31 by lfabbian          #+#    #+#             */
/*   Updated: 2022/10/28 15:59:54 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*tab;

	i = 0;
	if (!tab)
		return (NULL);
	tab = malloc(sizeof(char) * (len) + 1);
	if (start > ft_strlen(s))
		tab = ft_calloc(1, 1);
	while (len > 0 && s[i])
	{
		tab[i++] = s[start++];
		len--;
	}
	tab[i] = '\0';
	return (tab);
}

/*int main()
{
    char    *a;
    char test1[] = "hola";

    a = ft_substr(test1, 4, 20);
    printf("%s\n", a);
}*/