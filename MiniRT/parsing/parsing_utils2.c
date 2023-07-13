/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:35:52 by brisly            #+#    #+#             */
/*   Updated: 2023/07/13 12:04:38 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

float   parse_ratio(char *str, float ratio)
{
    if (!is_float(str))
        return (0.0);
    ratio = s_to_f(str);
    return (ratio);
}