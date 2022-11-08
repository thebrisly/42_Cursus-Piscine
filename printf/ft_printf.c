/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:51:03 by lfabbian          #+#    #+#             */
/*   Updated: 2022/11/08 15:26:46 by lfabbian         ###   ########.fr       */
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

/*int main()
{
	ft_printf("1: hello my name is %s and i am %c years old\n", "laura", 'a');
	printf("2: hello my name is %s and i am %d years old\n", "laura", 'a');
	printf("1.1: %d\n", printf("yop.\n"));
	printf("2.1: %d\n", ft_printf("yop.\n"));
	ft_printf("2.2: %d", ft_printf("yop.\n"));
}*/
