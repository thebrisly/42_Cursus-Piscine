/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 10:30:17 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/18 14:42:23 by rjuriens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

unsigned long long int	ft_atoi(char *str)
{
	unsigned int			sign;
	unsigned long long int	result;
	int						i;

	result = 0;
	sign = whitespaces(str, &i);
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	result *= sign;
	return (result);
}

char	*ft_itoa(unsigned long long int nbr)
{
	int		len;
	int		i;
	char	*result;

	len = int_len(nbr);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = len - 1;
	if (nbr == 0)
	{
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	while (nbr != 0)
	{
		result[i] = ((nbr % 10) + 48);
		nbr = nbr / 10;
		i--;
	}
	result[len] = '\0';
	return (result);
}

unsigned long long int	ft_pow(unsigned long long int nb, int power)
{
	unsigned long long int	res;

	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else
	{
		res = nb * ft_pow(nb, power - 1);
		return (res);
	}
}
