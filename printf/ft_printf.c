/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:51:03 by lfabbian          #+#    #+#             */
/*   Updated: 2022/11/09 10:34:23 by lfabbian         ###   ########.fr       */
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
	return (count);
}

/*int main()
{
	ft_printf("1: hello my name is %s and i am %i %% %d years old\n", "laura", 46, 2);
	printf("2: hello my name is %s and i am %i %% %d years old\n", "laura", 46, 2);
	printf("TEST COUNT ORDI: %d\n", printf("hello my name is %s and i am %i %% %d years old\n", "laura", 46, 2));
	printf("TEST COUNT MOI: %d\n", ft_printf("hello my name is %s and i am %i %% %d years old\n", "laura", 46, 2));
}*/
