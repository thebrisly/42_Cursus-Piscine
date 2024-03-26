/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:57:25 by fgrasset          #+#    #+#             */
/*   Updated: 2022/11/14 11:27:16 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ucheck_power(unsigned int n)
{
	int	i;

	i = 0;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	int		len;
	char	*res;

	len = ucheck_power(n) + 1;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	while (n != '\0')
	{
		res[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (res);
}

int	printf_u(unsigned int n)
{
	char	*nbr;
	int		len;

	nbr = ft_uitoa(n);
	ft_putstr_fd(nbr, 1);
	len = ft_strlen(nbr);
	free(nbr);
	return (len);
}
