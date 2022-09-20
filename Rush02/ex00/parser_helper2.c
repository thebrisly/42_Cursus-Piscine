/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:09:12 by saeby             #+#    #+#             */
/*   Updated: 2022/09/18 21:55:12 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	after_colon_index(int c[3], char *buffer, int f_size, int lc)
{
	while (!(ft_c_is_print(buffer[c[0] + c[2]])) && (c[0] + c[2]) < f_size)
		c[0]++;
	if (buffer[c[0] + c[2]] == '\n' && c[1] < lc - 1)
		return (dict_error());
	return (0);
}

void	letter_num_index(int c[3], char *buffer, int f_size)
{
	while (buffer[c[0] + c[2]] != '\n' && (c[0] + c[2]) < f_size)
		c[2]++;
}
