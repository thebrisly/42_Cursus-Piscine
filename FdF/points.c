/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathematics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:45:43 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/14 15:56:45 by lfabbian         ###   ########.fr       */
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
		//ft_printf("NEXT LINE\n");
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
	while (i < (env->map_w * env->map_h))
	{
		env->final_points[i].x =  env->initial_points[i].x + \
				cosf(env->alpha) * env->initial_points[i].z;
		env->final_points[i].y =  env->initial_points[i].y + \
				(sinf(env->alpha) * env->initial_points[i].z);
		printf("X: %f Y: %f\n",env->final_points[i].x, env->final_points[i].y);
		put_pixel(env, env->final_points[i].x + (WINDOW_WIDTH/2), env->final_points[i].y + WINDOW_HEIGHT/2, RED);
		//ft_printf("ixi");
		i++;
	}
}
