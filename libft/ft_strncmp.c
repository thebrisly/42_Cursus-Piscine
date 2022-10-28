/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:57:25 by brisly            #+#    #+#             */
/*   Updated: 2022/10/28 16:15:21 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

/*int main()
{
    char a[] = "hi how ar you";
    char b[] = "hi how ar3 you";

    printf("%d\n", ft_strncmp(a, b, 200));
}*/