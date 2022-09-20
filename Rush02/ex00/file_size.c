/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:34:11 by saeby             #+#    #+#             */
/*   Updated: 2022/09/18 11:12:22 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	file_size(char *file)
{
	char	t;
	int		f_dict;
	int		bytes_read;
	int		k;
	int		byte_count;

	k = 1;
	byte_count = 0;
	f_dict = open(file, O_RDONLY);
	while (k != 0)
	{
		bytes_read = read(f_dict, &t, 1);
		k = bytes_read;
		byte_count++;
	}
	return (byte_count);
}
