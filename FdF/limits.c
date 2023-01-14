/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:32:50 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/14 15:56:23 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	limits(t_env *env)
{
	int	c_x;
	int	c_y;

	c_y = 1;
	env->i = 0;
	while (c_y != env->map_h)
	{
		c_x = 1;
		while (c_x != env->map_w)
		{
			no_limit(env);
			c_x++;
		}
		if (c_x == env->map_w)
			right_limit(env);
		i++;
	}
	if (c_y == env->map_w)
	{
		if (c_x == env->map_w)
			exit(1);
		low_limit(env);
	}
}

void	no_limit(t_env *env)
{
	//alors on relie le point avec i + width et i + 1
	draw_line
}

void	right_limit()
{
	//on relie juste le point avec i + width
}

void	low_limit()
{
	//on relie juste le point avec celui de droite
}
