/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:45:28 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/19 16:31:00 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_signe(char *str)
{
	int	index;
	int	neg;

	index = 0;
	neg = 0;
	while ((str[index] >= 9 && str[index] <= 13) || str[index] == 32)
		index++;
	while (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			neg++;
		index++;
	}
	if (neg % 2 != 0)
		return (-1);
	else
		return (1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	negative;
	int	nombre;

	i = 0;
	negative = 0;
	nombre = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nombre = nombre * 10 + (str[i] - '0');
		i++;
	}
	if (nombre >= 2147483647)
	{
		nombre = 2147483647;
		return (nombre * ft_signe(str));
	}
	else
		return (nombre * ft_signe(str));
}
/*#include <stdio.h>
int	main()
{
	char *str;

	str = "\t \n  ----+-+2147fjdf384843";
	printf("%d \n", ft_atoi(str));
}*/
