/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 10:47:54 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/15 17:24:14 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//draw pixel
void put_pixel(t_env *env, int x, int y, int color)
{
	//ft_printf("JE SUIS DANS PUT PIXEL LINE");
    char *pxl;
    if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
    {
        pxl = env->address + (y * env->line_length + x * (env->bits_per_pixel / 8));
        *(unsigned int *)pxl = color;
    }
}

/*Line generation algorithm*/
/*DDA Line Drawing Algorithm*/
void draw_line(t_env *env, t_fpoint point0, t_fpoint point1)
{
	float	step;
	float	x;
	float	y;
	int		i;

	i = 0;
	printf("X0: %f Y0: %f X1: %f Y1 %f\n", point0.x, point0.y, point1.x, point1.y);
	env->delta[i].dx = fabsf(point1.x - point0.x);
	env->delta[i].dy = fabsf(point1.y - point0.y);
	//ft_printf("JE SUIS DANS DRAW LINE");
	if (env->delta[i].dx >= env->delta[i].dy)
		step = env->delta[i].dx;
	else
		step = env->delta[i].dy;
	//ft_printf("JE SUIS DANS DRAW LINE");
	env->delta[i].dx = env->delta[i].dx / step;
	env->delta[i].dy = env->delta[i].dy / step;
	x = point0.x;
	y = point0.y;
	while (i < step)
	{
		put_pixel(env, x, y, RED);
		x = x + env->delta[i].dx;
		y = y + env->delta[i].dy;
		i++;
	}
}

/*draw background for the bonus*/
