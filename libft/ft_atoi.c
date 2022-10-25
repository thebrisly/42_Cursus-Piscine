/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:39:09 by brisly            #+#    #+#             */
/*   Updated: 2022/10/25 15:55:27 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_atoi(const char *str)
{
    int i;
    int atoi;
    int sign;

    i = 0;
    atoi = 0;
    sign = 1;
    while (str[i] >= 9 && str[i] <= 13 || str[i] == 32)
        i++;
    while (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        atoi = atoi * 10 + (str[i] - '0');
        i++;
    }
    if (atoi >= 2147483647)
	{
        atoi = 2147483647;
		return (atoi * sign);
	}
    return (atoi * sign);
}

/* This function returns the converted integral number as an int value. 
If no valid conversion could be performed, it returns zero.*/

/*int main()
{
    char    number[] = "hello";
    
    printf("%d\n", ft_atoi(number));
}*/