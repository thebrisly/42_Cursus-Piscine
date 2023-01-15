/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:32:50 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/15 17:38:03 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	limits(t_env *env)
{
	int	c_x;
	int	c_y;

	c_y = 1;
	printf("X0: %f Y0: %f\n",env->final_points[env->i+1].x, env->final_points[env->i+1].y);
	while (c_y != env->map_h)
	{
		c_x = 1;
		while (c_x++ != env->map_w) //or <
			no_limit(env);
		if (c_x == env->map_w)
			right_limit(env);
		c_y++;
	}
	c_x = 1;
	if (c_y == env->map_w)
	{
		while (c_x != env->map_w)
		{
			low_limit(env);
			c_x++;
		}
	}
}

void	no_limit(t_env *env)
{
	//ft_printf("JE SUIS DANS LIMITE");
	right_limit(env);
	low_limit(env);
}

void	right_limit(t_env *env)
{
	float	x0;
	float	x1;
	float	y0;
	float	y1;
	int		i;

	i = env->i;
	ft_printf("INDEX: %d\n", i+1);
	//ft_printf("JE SUIS DANS right LIMITE");
	x0 = env->final_points[i].x;
	y0 = env->final_points[i].y;
	x1 = env->final_points[i+1].x;
	y1 = env->final_points[i+1].y;
	printf("X0: %f Y0: %f X1: %f Y1 %f\n", x0, y0, x1, y1);
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
