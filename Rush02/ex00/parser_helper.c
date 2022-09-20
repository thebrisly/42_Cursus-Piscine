/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:47:10 by saeby             #+#    #+#             */
/*   Updated: 2022/09/18 21:47:29 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	fill_buffer(char *buffer, char *file)
{
	int	i;
	int	bytes_read;
	int	f_dict;

	f_dict = open(file, O_RDONLY);
	if (f_dict == -1)
		return (-10);
	bytes_read = 1;
	i = 0;
	while (bytes_read != 0)
	{
		bytes_read = read(f_dict, &buffer[i], 1);
		i++;
	}
	return (0);
}

t_number	*alloc_nums_tab(int size)
{
	t_number	*tmp;

	tmp = (t_number *) malloc(size * sizeof(t_number));
	if (!tmp)
		return (NULL);
	return (tmp);
}

char	*alloc_buffer(int size)
{
	char	*tmp;

	tmp = (char *) malloc(size * sizeof(char));
	if (!tmp)
		return (NULL);
	return (tmp);
}

void	num_index(int c[3], char *buffer, int f_size)
{
	c[2] = 0;
	while (ft_c_is_num(buffer[c[0] + c[2]]) && (c[0] + c[2]) < f_size)
		c[2]++;
}

int	space_index(int c[3], char *buffer, int line_count)
{
	while (buffer[c[0] + c[2]] == ' ')
		c[0]++;
	if (buffer[c[0] + c[2]] != ':' && c[1] < line_count - 1)
		return (dict_error());
	c[0] += c[2] + 1;
	c[2] = 0;
	return (0);
}
