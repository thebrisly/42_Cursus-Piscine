/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:18:41 by lfabbian          #+#    #+#             */
/*   Updated: 2022/10/29 16:00:24 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n, int count)
{
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	if (n == 0)
		count++;
	while (n != 0)
	{
		n = (n / 10);
		count++;
	}
	return (count);
}

static char	*ft_putnbr(long n, int count, char *conversion, int position)
{
	while (position < count)
	{
		conversion[count - 2] = (n % 10) + '0';
		n = n / 10;
		count--;
	}
	return (conversion);
}

char	*ft_itoa(int n)
{
	char	*conversion;
	int		count;
	long	nbr;

	nbr = n;
	count = 1;
	count = ft_count(nbr, count);
	conversion = malloc(sizeof(char) * count);
	if (!conversion)
		return (NULL);
	if (nbr < 0)
	{
		conversion[0] = '-';
		conversion = ft_putnbr(-nbr, count, conversion, 2);
	}
	else
		conversion = (ft_putnbr(nbr, count, conversion, 1));
	conversion[count - 1] = '\0';
	return (conversion);
}

/*int main()
{
    char    *a;

    a = ft_itoa(-2147483649);
    printf("%s\n", a);
}*/