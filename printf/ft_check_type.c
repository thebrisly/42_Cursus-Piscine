/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:21:37 by brisly            #+#    #+#             */
/*   Updated: 2022/11/09 10:36:14 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_type(const char type, va_list args)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += (char)ft_put_c(va_arg(args, int));
	if (type == 's')
		count += ft_put_s(va_arg(args, char *));
	if (type == 'd' || type == 'i')
		count += ft_put_d_i(va_arg(args, int));
	/*if (type == 'p')*/
	if (type == 'u')
		count += ft_put_u(va_arg(args, unsigned int));
	/*if (type == 'x')
	if (type == 'X')*/
	if (type == '%')
		return (write(1, "%", 1));
	return (count);
}
