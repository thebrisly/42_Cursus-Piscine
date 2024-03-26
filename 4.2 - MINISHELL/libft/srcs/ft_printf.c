/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:19:03 by dferreir          #+#    #+#             */
/*   Updated: 2022/11/02 10:55:49 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	format(va_list args, char f_kind)
{
	int	len;

	len = 0;
	if (f_kind == 'c')
		len += ft_printchar(va_arg(args, int));
	else if (f_kind == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (f_kind == 'p')
		len += ft_printptr(va_arg(args, unsigned long long));
	else if (f_kind == 'd' || f_kind == 'i')
		len += ft_printnbr(va_arg(args, int));
	else if (f_kind == 'u')
		len += ft_printunbr(va_arg(args, unsigned int));
	else if (f_kind == 'X' || f_kind == 'x')
		len += ft_printhex(va_arg(args, unsigned int), f_kind);
	else if (f_kind == '%')
	{
		write (1, "%", 1);
		len++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += format(args, str[i + 1]);
			i++;
		}
		else
		{
			write (1, &str[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

/*int main()
{
	char str[] = "Hello";
	int nbr = -42;

	printf("%s and %d", str, nbr);
	return (0);
}*/
