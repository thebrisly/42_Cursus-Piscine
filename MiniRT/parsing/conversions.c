/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:34:20 by brisly            #+#    #+#             */
/*   Updated: 2023/07/12 22:39:47 by brisly           ###   ########.fr       */
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