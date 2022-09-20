/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helper3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 21:26:24 by saeby             #+#    #+#             */
/*   Updated: 2022/09/18 21:54:46 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	parse_helper(int c[5], char *buf, t_number *nums)
{
	num_index(c, buf, c[3]);
	nums[c[1]].int_num = ft_strdup(&buf[c[0]], c[2] - 1);
	if (space_index(c, buf, c[4]) == -10)
		return (dict_error());
	if (after_colon_index(c, buf, c[3], c[4]) == -10)
		return (dict_error());
	letter_num_index(c, buf, c[3]);
	nums[c[1]].letter_num = ft_strdup(&buf[c[0]], c[2] - 1);
	c[1]++;
	c[0] += c[2] + 1;
	return (0);
}
