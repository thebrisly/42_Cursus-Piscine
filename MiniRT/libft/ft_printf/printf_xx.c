/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_xx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:21:42 by fgrasset          #+#    #+#             */
/*   Updated: 2022/11/14 11:26:58 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count(unsigned int n)
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

int	printf_xx(unsigned int n)
{
	if (n >= 16)
	{
		printf_xx(n / 16);
		printf_xx(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd(n + '0', 1);
		else
			ft_putchar_fd((n - 10) + 'A', 1);
	}
	return (count(n));
}
