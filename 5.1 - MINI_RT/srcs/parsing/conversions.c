/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:34:20 by brisly            #+#    #+#             */
/*   Updated: 2023/07/17 13:44:07 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minirt.h"

int	is_float(char *str)
{
	bool	first;
	int		i;

	i = 0;
	first = false;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9' && !first)
			i++;
		else if (str[i] == '.' && str[i + 1])
		{
			if (first)
				return (0);
			first = true;
			i++;
		}
		else if (str[i] >= '0' && str[i] <= '9' && first)
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_positive(char *str)
{
	if (str[0] == '-')
		return (0);
	else
		return (1);
}

int	is_range(float number)
{
	if (number >= -1 && number <= 1)
		return (1);
	else
		return (0);
}

bool	is_color(char *str)
{
	int	i;
	int	color;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	color = ft_atoi(str);
	if (color >= 0 && color <= 255)
		return (true);
	else
		return (false);
}

float	s_to_f(char *str)
{
	float	sum;
	float	prec;
	float	div;
	float	sign;

	prec = 0.0;
	div = 1.0;
	sign = 1.0;
	if (str && str[0] == '-')
		sign *= -1.0;
	sum = (float)ft_atoi(str);
	while (*str && *str != '.')
		str++;
	if (*str++ == '.')
	{
		while (*str >= '0' && *str <= '9')
		{
			div *= 10.0;
			prec += (*str - '0') / div;
			str++;
		}
		sum += prec * sign;
	}
	return (sum);
}
