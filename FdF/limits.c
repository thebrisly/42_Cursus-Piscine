/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:32:50 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/20 10:27:07 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	limits(t_env *env)
{
	env->c_y = 1;
	env->i = 0;
	while (env->c_y != env->map_h)
	{
		env->c_x = 1;
		while (env->c_x < env->map_w)
			no_limit(env);
		if (env->c_x == env->map_w)
		{
			low_limit(env);
			env->i++;
		}
		env->c_y++;
	}
	env->c_x = 1;
	if (env->c_y == env->map_h)
	{
		while (env->c_x != env->map_w)
		{
			right_limit(env);
			env->i++;
		}
	}
	free (env->final_points);
}

void	no_limit(t_env *env)
{
	right_limit(env);
	low_limit(env);
	env->i++;
}

void	right_limit(t_env *env)
{
	float	x0;
	float	x1;
	float	y0;
	float	y1;

	x0 = env->final_points[env->i].x;
	y0 = env->final_points[env->i].y;
	x1 = env->final_points[env->i + 1].x;
	y1 = env->final_points[env->i + 1].y;
	env->c_x++;
	draw_line(env, (t_fpoint){x0, y0}, (t_fpoint){x1, y1});
}

void	low_limit(t_env *env)
{
	float	x0;
	float	x1;
	float	y0;
	float	y1;

	x0 = env->final_points[env->i].x;
	y0 = env->final_points[env->i].y;
	x1 = env->final_points[env->i + env->map_w].x;
	y1 = env->final_points[env->i + env->map_w].y;
	draw_line(env, (t_fpoint){x0, y0}, (t_fpoint){x1, y1});
}
