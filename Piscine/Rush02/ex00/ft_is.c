/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 10:25:08 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/18 16:21:55 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	whitespaces(char *str, int *ptr_i)
{
	int	count;
	int	i;

	i = 0;
	count = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] && (str[i] == 43 || str[i] == 45))
	{
		if (str[i] == 45)
			count *= -1;
		i++;
	}
	*ptr_i = i;
	return (count);
}

int	ft_c_is_num(char c)
{
	if (!(c >= 48 && c <= 57))
		return (0);
	return (1);
}

int	ft_c_is_print(char c)
{
	if (!(c >= 33 && c <= 126))
		return (0);
	return (1);
}

int	ft_char_is_alpha(char c)
{
	if (!(c >= 65 && c <= 90) && !(c >= 97 && c <= 122))
		return (0);
	return (1);
}

int	ft_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
