/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:23:53 by dferreir          #+#    #+#             */
/*   Updated: 2022/11/02 10:57:06 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printnbr(int n)
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
		nbr = ft_itoa(n);
		len += ft_printstr(nbr);
		free (nbr);
	}
	return (len);
}
