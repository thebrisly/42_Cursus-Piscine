/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:30:41 by brisly            #+#    #+#             */
/*   Updated: 2022/10/28 11:07:40 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			j = i;
		i++;
	}
	if (s[i] == c)
		return ((char *) &s[i]);
	if (i > 0)
		return ((char *) &s[j]);
	return (NULL);
}

/*#include <stdio.h>
int main()
{
    char a[] = "http://www.tutorialspoint.com";
    printf("%s\n", ft_strrchr(a, 't'));
}*/