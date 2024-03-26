/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:36:46 by dferreir          #+#    #+#             */
/*   Updated: 2022/11/02 10:56:29 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	dec_to_hex(unsigned int nbr, char type, unsigned int *len)
{
	if (nbr >= 16)
	{
		dec_to_hex(nbr / 16, type, len);
		dec_to_hex(nbr % 16, type, len);
	}
	else
	{
		if (nbr <= 9)
			*len += ft_printchar(nbr + '0');
		else
		{
			nbr -= 10;
			if (type == 'X')
				*len += ft_printchar(nbr + 'A');
			if (type == 'x')
				*len += ft_printchar(nbr + 'a');
		}
	}
}

int	ft_printhex(unsigned int nbr, char type)
{
	unsigned int	len;

	len = 0;
	if (!nbr)
		return (write (1, "0", 1));
	else
		dec_to_hex(nbr, type, &len);
	return (len);
}
