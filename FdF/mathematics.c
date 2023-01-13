/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathematics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:45:43 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/13 15:30:19 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	three_dim_point(t_env *env)
{
	int	i;

	i = 0;
	env->initial_points = malloc(env->map_h * env->map_w * (sizeof(t_ipoint)));
	if (!env->initial_points)
		error("Malloc failed");
	env->y = 0;
	while (env->y < env->map_h)
	{
		env->x = 0;
		while (env->x < env->map_w)
		{
			env->initial_points[i] = (t_ipoint){env->x, env->y, env->final_tab[env->y][env->x]};
			//ft_printf("X: %d Y: %d Z: %d\n", env->initial_points[i].x, env->initial_points[i].y, env->initial_points[i].z);
			i++;
			env->x++;
		}
		env->y++;
	}
}

void	two_dim_point(t_env *env)
{
	int	i;
	i = 0;
	env->final_points = malloc(env->map_h * env->map_w * (sizeof(t_fpoint)));
	if (!env->final_points)
		error("Malloc failed");
	env->final_points[i].x = env->initial_points[i].x \
			+ (cos(env->alpha) * env->initial_points[i].z);
	env->final_points[i].y = env->initial_points[i].x \
			+ (sin(env->alpha) * env->initial_points[i].z);

	/*i = 0;
	while (i < 800)
	{
		put_pixel(env, WINDOW_WIDTH/2 + i, 100, 0xFF0000);
		mlx_put_image_to_window(env->mlx, env->win, env->image, 0, 0);
		i++;
	}*/
	//put_pixel(env, WINDOW_WIDTH/2 + i, WINDOW_HEIGHT/2, 0xFF0000);
}

/*Line generation algorithm*/
void	bresenham()
{

}
