/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:51:03 by lfabbian          #+#    #+#             */
/*   Updated: 2022/11/12 12:07:50 by lfabbian         ###   ########.fr       */
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
	if (count < 0)
		return (-1);
	return (count);
}
