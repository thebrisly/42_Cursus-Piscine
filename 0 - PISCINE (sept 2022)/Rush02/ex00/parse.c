/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 13:52:01 by saeby             #+#    #+#             */
/*   Updated: 2022/09/18 21:59:47 by rjuriens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*ft_strdup(char *src, int offset)
{
	char	*dest;
	int		i;

	dest = malloc((offset + 2) * sizeof(char));
	i = 0;
	while (i <= offset)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

t_number	*parse(char *file)
{
	char		*buffer;
	t_number	*nums;
	int			c[5];

	c[3] = file_size(file);
	c[4] = count_lines(file);
	nums = alloc_nums_tab(count_lines(file) + 1);
	buffer = alloc_buffer(file_size(file) + 2);
	if (fill_buffer(buffer, file) == -10)
		return (NULL);
	c[0] = 0;
	c[1] = 0;
	while (c[0] < c[3])
	{
		parse_helper(c, buffer, nums);
	}
	if (nums[count_lines(file) - 1].int_num[0] == '\0')
		return (NULL);
	return (nums);
}
