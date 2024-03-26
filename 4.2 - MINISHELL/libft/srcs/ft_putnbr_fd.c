/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:29:32 by dferreir          #+#    #+#             */
/*   Updated: 2022/10/24 10:44:49 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	str[10];
	long	nbr;
	int		i;

	nbr = n;
	i = 0;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr *= -1;
	}
	while (nbr >= 10)
	{
		str[i++] = nbr % 10 + '0';
		nbr /= 10;
	}
	str[i] = nbr + '0';
	while (i >= 0)
		ft_putchar_fd(str[i--], fd);
}
