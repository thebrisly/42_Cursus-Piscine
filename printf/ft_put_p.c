/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:30:34 by lfabbian          #+#    #+#             */
/*   Updated: 2022/11/11 16:08:37 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_p(void *arg)
{
	char				*alpha;
	unsigned int		*arg2;
	int					count;

	arg2 = (unsigned int *)arg;
	alpha = "0123456789abcdef";
	count = 0;
	count += ft_put_s("0x");
	count += ft_base16(arg2, alpha);
	return (count);
}


int	ft_put_p(uintptr_t *arg)
{
	char				*alpha;
	int					count;

	alpha = "0123456789abcdef";
	count = 0;
	count += ft_put_s("0x");
	count += ft_base16(arg, alpha);
	return (count);
}
