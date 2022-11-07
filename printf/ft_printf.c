/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:51:03 by lfabbian          #+#    #+#             */
/*   Updated: 2022/11/07 09:11:08 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start (args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ...;
		}
		else
		{
			
		}
	}
	va_end (args);
	return (count);
}

int main()
{
	printf("1: hello my name is %s and i am %d old\n", "laura", 23);
	printf("2: hello my name is %s and i am %d old\n", "laura", 23);
	printf("1.1: %d\n", printf("something random.\n"));
	printf("2.1: %d\n", ft_printf("something random.\n"));
	ft_printf("2.2: %d", ft_printf("something random.\n"));
}