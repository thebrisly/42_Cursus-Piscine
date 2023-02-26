/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:35:01 by dferreir          #+#    #+#             */
/*   Updated: 2022/10/17 13:43:30 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			++i;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/*void test(int size)
{
    char string[] = "Hello there, Venus";
    char buffer[19];
    int r;

    r = strlcpy(buffer,string,size);

    printf("Copied '%s' into '%s', length %d\n",
            string,
            buffer,
            r
          );
}

void test2(int sizes)
{
    char strings[] = "Hello there, Venus";
    char buffers[19];
    int rs;

    rs = ft_strlcpy(buffers,strings,sizes);

    printf("Copied '%s' into '%s', length %d 2\n",
            strings,
            buffers,
            rs
          );
}

int main()
{
    test(19);
	test2(19);
    test(10);
	test2(10);
    test(1);
	test2(1);
    test(0);
	test2(0);

    return(0);
}*/
