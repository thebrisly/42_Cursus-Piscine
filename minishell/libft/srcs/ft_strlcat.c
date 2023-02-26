/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:28:31 by dferreir          #+#    #+#             */
/*   Updated: 2022/10/20 13:29:12 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	length_dst;
	size_t	length_src;

	i = 0;
	length_dst = ft_strlen(dst);
	length_src = ft_strlen(src);
	if (length_dst < dstsize - 1 && dstsize > 0)
	{
		while (*dst)
			dst++;
		while (*src && length_dst + i < dstsize - 1)
		{
			*dst = *src;
			dst++;
			src++;
			i++;
		}
		*dst = 0;
	}
	if (length_dst >= dstsize)
		length_dst = dstsize;
	return (length_dst + length_src);
}

/*int main()
{
    char first[] = "This is ";
    char last[] = "a potentially long string";
    int r;
    int size = 16;
    char buffer[size];

    strcpy(buffer,first);
    r = strlcat(buffer,last,size);

    puts(buffer);
    printf("Value returned: %d\n",r);
    if( r > size )
        puts("String truncated");
    else
        puts("String was fully copied");

    char firsts[] = "This is ";
    char lasts[] = "a potentially long string";
    int rs;
    int sizes = 16;
    char buffers[sizes];

    strcpy(buffers,firsts);
    rs = ft_strlcat(buffers,lasts,sizes);

    puts(buffers);
    printf("Value returned: %d 2\n",rs);
    if( rs > sizes )
        puts("String truncated 2");
    else
        puts("String was fully copied 2");

    return(0);
}*/
