/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:03:25 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/08 15:20:53 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void map_info(t_env env, char *file)
{
	int fd;
	char *line;
	char **tab;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
    	ft_printf("Map Error");
		exit(1);
	}
	env.map_h = 0;
	env.map_w = 0;
	line = get_next_line(fd);
	tab = ft_split(line, ' ');
	while (tab[env.map_w])
		env.map_w++;
	ft_printf("---- %d ----\n", env.map_w);
	while (line)
	{
		env.map_h++;
		line = get_next_line(fd);
	}
	ft_printf("---- %d ----\n", env.map_h);
	close (fd);
}

void parse_map()
{

}

int env_init(t_env env)
{
	env.alpha = 0.5;
	env.mlx = mlx_init();
	if (env.mlx == NULL)
	{
		free(env.mlx);
		return (MLX_ERROR);
	}
	env.win = mlx_new_window(env.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FdF");
	if (env.win == NULL)
		return (MLX_ERROR);
	env.image = mlx_new_image(env.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	env.address = mlx_get_data_addr(env.image, &env.bits_per_pixel, &env.line_length, &env.endian);
	h_management(env);
	mlx_loop(env.mlx);
	return (0);
}
