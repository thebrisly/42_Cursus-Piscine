/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 10:42:11 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/18 15:15:08 by rjuriens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	int_len(unsigned long long int nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
