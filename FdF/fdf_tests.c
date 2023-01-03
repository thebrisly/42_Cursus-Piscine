/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:17:16 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/03 17:55:30 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define	WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

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
	void	*mlx;
	void	*mlx_win;
	t_data	image;
	int		i;

	i = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	image.img = mlx_new_image(mlx, 1920, 1080);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
	while (i < 800)
	{
		ft_put_pixel(&image, WINDOW_WIDTH/2 + i, WINDOW_HEIGHT/2, 0xFF0000);
		mlx_put_image_to_window(mlx, mlx_win, image.img, 0, 0);
		i++;
	}
	i = 0;
	while (i < 800)
	{
		ft_put_pixel(&image, WINDOW_WIDTH/2 + i, 100, 0xFF0000);
		mlx_put_image_to_window(mlx, mlx_win, image.img, 0, 0);
		i++;
	}
	mlx_loop(mlx);
}
