/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 10:47:54 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/14 15:57:05 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//draw pixel
void put_pixel(t_env *env, int x, int y, int color)
{
    char *pxl;
    if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
    {
        pxl = env->address + (y * env->line_length + x * (env->bits_per_pixel / 8));
        *(unsigned int *)pxl = color;
    }
}

/*Line generation algorithm*/
/*
void draw_line(t_env *env)
{
    int p;

	env->delta.dx = x1 - x0;
	env->delta.dy = y1 - y0;
	env->x = x0;
	env->y = y0;

	p = 2 * dy - dx;

	while (env->x < x1)
	{
		if (p >= 0)
		{
			put_pixel(env, x,y,7);
			y = y + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			put_pixel(env, x,y,7);
			p = p + 2 * dy;
		}
		x=x+1;
	}
}
*/
