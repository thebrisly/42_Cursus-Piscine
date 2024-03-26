/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:30:41 by brisly            #+#    #+#             */
/*   Updated: 2022/10/29 14:30:37 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*occ;

	occ = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			occ = (char *) &s[i];
		i++;
	}
	if (s[i] == (char) c)
		occ = (char *) &s[i];
	return (occ);
}

/*#include <stdio.h>
int main()
{
    char a[] = "http://www.tutorialspoint.com";
    printf("%s\n", ft_strrchr(a, 't'));
}*/