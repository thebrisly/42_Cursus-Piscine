/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:28:47 by fgrasset          #+#    #+#             */
/*   Updated: 2022/11/14 13:20:58 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	countlong(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != '\0')
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static int	printf_long(unsigned long n)
{
	if (n >= 16)
	{
		printf_long(n / 16);
		printf_long(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd(n + '0', 1);
		else
			ft_putchar_fd((n - 10) + 'a', 1);
	}
	return (countlong(n));
}

int	printf_p(unsigned long cpy)
{
	ft_putstr_fd("0x", 1);
	return (printf_long(cpy) + 2);
}
