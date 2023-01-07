/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:25:40 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/07 15:52:58 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_read_fd(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
    	ft_printf("Error opening file");
    	return (0);
  	}
	return (fd);
}


int main(int argc, char **argv)
{
	int fd;

	if (argc == 2)
	{
		fd = ft_read_fd(argv[1]);
		ft_printf("GNL 1: %s", get_next_line(fd));
	}
	else
		ft_printf("Wrong number of args");
}
