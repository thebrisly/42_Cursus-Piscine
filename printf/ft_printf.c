/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:51:03 by lfabbian          #+#    #+#             */
/*   Updated: 2022/11/11 15:42:48 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			count += ft_put_c(str[i]);
		i++;
	}
	va_end (args);
	if (!count)
		return (-1);
	return (count);
}

int main()
{
    int x = 59;
	//printf("ordi: %d\n", printf(" NULL %s NULL\n", NULL));
	ft_printf(" NULL %s NULL", NULL);
	printf("ordi: %d\n", ft_printf(" NULL %s NULL\n", NULL));
	ft_printf("1: hello my name is %s and i am %i %% %d years old\n", "laura", 46, 2);
	printf("2: hello my name is %s and i am %i %% %d years old\n", "laura", 46, 2);
	printf("value of HEXA ORDI : %X\n", 10956);
	printf("value of HEXA ORDI : %X\n", 146);
	ft_printf("value of HEXA moi :	%X\n", 10956);
	ft_printf("value of HEXA moi :	%X\n", 146);
	printf("TEST COUNT ORDI: %d\n", printf("hello my name is %s and i am %i %% %d years old\n", "laura", 46, 2));
	printf("TEST COUNT MOI: %d\n", ft_printf("hello my name is %s and i am %i %% %d years old\n", "laura", 46, 2));

	printf("---------------------------------------------------------------------------\n");
	printf("ORDI VALUE %%p: %p\n", "hi");
	ft_printf("MY VALUE %%p: %p\n", "hi");
	printf("Value using %%x: %x\n", x);
}
