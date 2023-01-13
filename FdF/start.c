/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:03:25 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/13 15:30:25 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_info(t_env *env, char *file)
{
	int		fd;
	char	*line;
	char	**tab;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("Map error !");
	env->map_h = 0;
	env->map_w = 0;
	line = get_next_line(fd);
	tab = ft_split(line, ' ');
	while (tab[env->map_w])
		env->map_w++;
	while (line)
	{
		env->map_h++;
		line = get_next_line(fd);
	}
	close (fd);
}

void	parse_map(t_env *env, char *file)
{
	int		fd;
	char	*line;
	char	**line_tab;

	env->y = 0;
	fd = open(file, O_RDONLY);
	env->final_tab = malloc(env->map_h * sizeof(int *));
	if (!env->final_tab)
		error("Malloc failed");
	while (env->y < env->map_h)
	{
		env->final_tab[env->y] = malloc(env->map_w * sizeof(int));
		if (!env->final_tab[env->y])
			error("Malloc failed");
		line = get_next_line(fd);
		line_tab = ft_split(line, ' ');
		env->x = 0;
		while (env->x < env->map_w)
		{
			env->final_tab[env->y][env->x] = ft_atoi(line_tab[env->x]);
			//ft_printf("LINE: %d, COL: %d, ALT: %d\n", env->y, env->x, env->final_tab[env->y][env->x]);
			env->x++;
		}
		env->y++;
	}
}

int	env_init(t_env *env)
{
	env->alpha = 0.5;
	env->mlx = mlx_init();
	if (env->mlx == NULL)
	{
		free(env->mlx);
		return (MLX_ERROR);
	}
	env->win = mlx_new_window(env->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FdF");
	if (env->win == NULL)
		return (MLX_ERROR);
	env->image = mlx_new_image(env->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	env->address = mlx_get_data_addr(env->image, &env->bits_per_pixel, &env->line_length, &env->endian);
	//two_dim_point(env);
	h_management(env);
	mlx_loop(env->mlx);
	return (0);
}
