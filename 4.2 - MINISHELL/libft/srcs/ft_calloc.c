/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 09:49:32 by dferreir          #+#    #+#             */
/*   Updated: 2022/10/20 14:09:05 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (0);
	ft_memset(ptr, 0, (count * size));
	return (ptr);
}

/*int main()
{
    int i, * ptr, sum = 0;
    ptr = calloc(10, sizeof(int));
    if (ptr == NULL)
	{
        printf("Error! memory not allocated.");
        exit(0);
    }
    printf("Building and calculating the sequence sum of the first 10 terms \n");
    for (i = 0; i < 10; ++i)
	{
		* (ptr + i) = i;
        sum += * (ptr + i);
    }
    printf("Sum = %d", sum);
    free(ptr);
    return 0;
}*/
