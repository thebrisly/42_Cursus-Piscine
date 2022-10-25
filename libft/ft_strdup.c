/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:18:39 by lfabbian          #+#    #+#             */
/*   Updated: 2022/10/25 13:53:08 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *s1)
{
    char    *tab;
    int     i;
    int     len;

    len = ft_strlen(s1);
    i = 0;
    tab = malloc(sizeof(char) * len);
    if (!tab)
        return  (NULL);
    while (s1[i])
    {
        tab[i] = s1[i];
        i++;
    }
    return (tab);
}

/*int	main()
{
	char chaine[] = "HEllo World"; 
	//printf("%s", strdup("Hello World"));
	printf("%s", ft_strdup(chaine));
}*/