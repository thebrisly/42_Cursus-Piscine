/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:17:16 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/08 10:54:14 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	key_hook()
{
	printf("Hello from key_hook!\n");
	return (0);
}

int	main(void)
{
	t_vars	vars;
	t_data	image;
	int		i;

	i = 0;
	vars.mlx = mlx_init(); //display init
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!"); //window init
	//init_errors(vars.mlx, vars.win);
	image.img = mlx_new_image(vars.mlx, 1920, 1080); //image init
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
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
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);

	// Creer un hook qui permet de faire ca: en cliquant sur ESC
	//mlx_destroy_windows(vars.mlx, vars.win);
	//mlx_destroy_display(vars.mlx);
	//free(vars.lmx);
}
