/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:51:03 by lfabbian          #+#    #+#             */
/*   Updated: 2022/11/08 22:29:20 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	return(write(1, &c, 1));
}


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
			i++;
			count += ft_check_type(str[i], args);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end (args);
	return (count);
}

int main()
{
	ft_printf("1: hello my name is %s and i am %d years old\n", "laura", 23);
	printf("2: hello my name is %s and i am %d years old\n", "laura", 23);
	printf("1.1: %d", printf("yop %s %d.\n", "laura", 23));
	printf("2.1: %d", ft_printf("yop %s %d.\n", "laura", 23));
	printf("TEST INT ORDI: %d", printf("%d.\n", 23));
	printf("TEST INT MOI: %d\n", ft_printf("%d.\n", 23));
	ft_printf("2.2: %d", ft_printf("yop.\n"));
}
