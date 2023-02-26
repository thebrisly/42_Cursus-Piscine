/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:53:42 by dferreir          #+#    #+#             */
/*   Updated: 2022/10/24 11:14:42 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	new_len;

	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	new_len = ft_strlen(s + start);
	if (new_len < len)
		len = new_len;
	new_str = (char *)malloc(len + 1);
	if (!s || !new_str)
		return (0);
	i = 0;
	while (i < len)
		new_str[i++] = s[start++];
	new_str[i] = 0;
	return (new_str);
}
/*
int main()
{
    char src[] = "substr function Implementation";

    int m = 5;
    int n = 3;

    char* dest = ft_substr(src, m, n);

    printf("%s\n", dest);

    return 0;
}*/
