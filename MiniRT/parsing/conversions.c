/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:34:20 by brisly            #+#    #+#             */
/*   Updated: 2023/07/13 11:57:51 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

int	is_float(char *str)
{
    bool    first;
    bool    second;
    int i;

    i = 0;
    first = false;
    second = false;
    if (str[0] == '+' || str[0] == '-')
        i++;
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9' && !first)
            i = i;
        else if (str[i] == '.')
        {
            if (first)
                return (0);
            first = true;
        }
        else if (str[i] >= '0' && str[i] <= '9' && first)
            second = true;
        else
            return (0);
        i++;
    }
    return (first && second);
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