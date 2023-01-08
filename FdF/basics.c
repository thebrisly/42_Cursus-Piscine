/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:03:25 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/08 11:10:06 by lfabbian         ###   ########.fr       */
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

int env_init()
{
	vars	vars;

	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
	{
		free(vars.mlx);
		return (MLX_ERROR);
	}
	vars.win = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FdF");
	if (vars.win == NULL)
		return (MLX_ERROR);
	mlx_loop(vars.mlx);
}
