/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:45:43 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/18 14:04:07 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*Fill in the three-dimensional table*/
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
			env->initial_points[i] = (t_ipoint){env->x, env->y, \
								env->final_tab[env->y][env->x]};
			i++;
			env->x++;
		}
		env->y++;
	}
	free_final_tab(env);
}

/*Fill in the two-dimensional table*/
void	two_dim_point(t_env *env)
{
	int	i;

	i = 0;
	env->final_points = malloc(env->map_h * env->map_w * (sizeof(t_fpoint)));
	if (!env->final_points)
		error("Malloc failed");
	while (i < (env->map_w * env->map_h))
	{
		env->final_points[i].x = env->initial_points[i].y \
				* cosf(env->alpha) + env->initial_points[i].y \
				* cosf(env->alpha + 2) \
				+ (env->initial_points[i].z * env->altitude) \
				* cosf(env->alpha - 2);
		env->final_points[i].y = env->initial_points[i].x \
				* sinf(env->alpha) + env->initial_points[i].y \
				* sinf(env->alpha + 2) \
				+ (env->initial_points[i].z * env->altitude) \
				* sinf(env->alpha - 2);
		env->final_points[i].x *= env->scale;
		env->final_points[i].y *= env->scale;
		i++;
	}
}
