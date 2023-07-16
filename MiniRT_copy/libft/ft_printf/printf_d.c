/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:32:45 by fgrasset          #+#    #+#             */
/*   Updated: 2022/11/11 16:50:10 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_d(int n)
{
	char	*nbr;
	int		len;

	nbr = ft_itoa(n);
	ft_putstr_fd(nbr, 1);
	len = ft_strlen(nbr);
	free(nbr);
	return (len);
}
