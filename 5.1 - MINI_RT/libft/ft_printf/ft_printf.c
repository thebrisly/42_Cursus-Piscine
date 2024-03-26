/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:32:55 by fabien            #+#    #+#             */
/*   Updated: 2022/11/14 12:52:18 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_flag(va_list args, char flag)
{
	if (flag == 'c')
		return (printf_c(va_arg(args, int)));
	else if (flag == 's')
		return (printf_s(va_arg(args, char *)));
	else if (flag == 'd' || flag == 'i')
		return (printf_d(va_arg(args, int)));
	else if (flag == 'u')
		return (printf_u(va_arg(args, unsigned int)));
	else if (flag == 'x')
		return (printf_x(va_arg(args, unsigned int)));
	else if (flag == 'X')
		return (printf_xx(va_arg(args, unsigned int)));
	else if (flag == 'p')
		return (printf_p(va_arg(args, unsigned long)));
	else
		return (0);
}

int	ft_printf(const char *string, ...)
{
	int		i;
	int		res;
	va_list	args;

	va_start(args, string);
	i = -1;
	res = 0;
	while (string[++i])
	{
		if (string[i] == '%')
		{
			if (string[i + 1] == '%')
				res += write(1, "%", 1);
			else
				res += check_flag(args, string[i + 1]);
			i++;
		}
		else
			res += write(1, &string[i], 1);
	}
	va_end(args);
	return (res);
}
