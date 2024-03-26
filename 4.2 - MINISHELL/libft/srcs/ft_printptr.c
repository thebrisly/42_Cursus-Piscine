/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:31:26 by dferreir          #+#    #+#             */
/*   Updated: 2022/11/02 10:57:24 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	to_hex(unsigned long long nbr, unsigned int *len)
{
	if (nbr >= 16)
	{
		to_hex(nbr / 16, len);
		to_hex(nbr % 16, len);
	}
	else
	{
		if (nbr <= 9)
			*len += ft_printchar(nbr + '0');
		else
			*len += ft_printchar(nbr - 10 + 'a');
	}
}

int	ft_printptr(unsigned long long ptr)
{
	unsigned int	len;

	len = 2;
	write (1, "0x", 2);
	if (!ptr)
		len += write (1, "0", 1);
	else
		to_hex(ptr, &len);
	return (len);
}

/*int main()
{
	int num = 10;
	int *ptr = &num;
	ft_printptr(ptr);
	printf("\n%p", ptr);
	return 0;
}*/
