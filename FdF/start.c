/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:03:25 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/22 10:21:33 by lfabbian         ###   ########.fr       */
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
	line = get_next_line(fd);
	if (!line)
		error("Map empty !");
	tab = ft_split(line, ' ');
	while (tab[env->map_w])
	{
		free(tab[env->map_w]);
		env->map_w++;
	}
	while (line)
	{
		free(line);
		env->map_h++;
		line = get_next_line(fd);
	}
	free(line);
	free(tab);
	close (fd);
}

void	check_format(t_env *env, char *file)
{
	int		fd;
	char	*line;
	char	**tab;
	int		x;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		tab = ft_split(line, ' ');
		free(line);
		x = 0;
		while (tab[x])
		{
			free(tab[x]);
			x++;
		}
		free(tab);
		if (x < env->map_w || x > env->map_w)
			error("Wrong map format");
		line = get_next_line(fd);
	}
	free(line);
	close (fd);
}

void	parse_map(t_env *env, char *file)
{
	int		fd;
	char	*line;
	char	**line_tab;

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
		free(line);
		env->x = -1;
		while (++env->x < env->map_w)
		{
			env->final_tab[env->y][env->x] = ft_atoi(line_tab[env->x]);
			free(line_tab[env->x]);
		}
		env->y++;
		free(line_tab);
	}
}

int	env_init(t_env *env)
{
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
	env->address = mlx_get_data_addr(env->image, &env->bits_per_pixel, \
	&env->line_length, &env->endian);
	two_dim_point(env);
	limits(env);
	h_management(env);
	mlx_loop_hook(env->mlx, render, env);
	mlx_loop(env->mlx);
	return (0);
}

int	render(t_env *env)
{
	draw_background(env);
	two_dim_point(env);
	limits(env);
	mlx_put_image_to_window(env->mlx, env->win, env->image, 0, 0);
	return (0);
}
