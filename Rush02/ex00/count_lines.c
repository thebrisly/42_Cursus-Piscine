/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 13:22:29 by saeby             #+#    #+#             */
/*   Updated: 2022/09/18 11:15:15 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	count_lines(char *file)
{
	int		f_dict;
	char	t;
	int		bytes_read;
	int		k;
	int		line_count;

	k = 1;
	t = 0;
	line_count = 0;
	f_dict = open(file, O_RDONLY);
	while (k != 0)
	{
		bytes_read = read(f_dict, &t, 1);
		k = bytes_read;
		if (t == '\n')
			line_count++;
	}
	return (line_count - 1);
}
