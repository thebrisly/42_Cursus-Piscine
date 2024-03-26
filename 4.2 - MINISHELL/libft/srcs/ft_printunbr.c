/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:23:53 by dferreir          #+#    #+#             */
/*   Updated: 2022/11/02 10:57:55 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	long	new_nbr;
	int		len;

	new_nbr = n;
	len = (new_nbr <= 0);
	while (n)
	{
		len++;
		n /= 10;
	}
	str = ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (0);
	str[len--] = 0;
	if (new_nbr < 0)
		new_nbr *= -1;
	while (new_nbr > 0)
	{
		str[len--] = new_nbr % 10 + '0';
		new_nbr /= 10;
	}
	return (str);
}

int	ft_printunbr(unsigned int n)
{
	char	*nbr;
	int		len;

	len = 0;
	if (n == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	else
	{
		nbr = ft_uitoa(n);
		len += ft_printstr(nbr);
		free (nbr);
	}
	return (len);
}
