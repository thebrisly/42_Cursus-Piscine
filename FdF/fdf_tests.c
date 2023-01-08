/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:17:16 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/08 14:09:26 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_put_pixel(t_data *data, int x, int y, int color)
{
    char *pxl;

    if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
    {
        pxl = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int *)pxl = color;
    }
}

int	main(void)
{
	while (i < 800)
	{
		ft_put_pixel(&image, WINDOW_WIDTH/2 + i, WINDOW_HEIGHT/2, 0xFF0000);
		mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
		i++;
	}
	i = 0;
	while (i < 800)
	{
		ft_put_pixel(&image, WINDOW_WIDTH/2 + i, 100, 0xFF0000);
		mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
		i++;
	}
	mlx_loop(vars.mlx);
}
