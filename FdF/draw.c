/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 10:47:54 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/13 15:30:24 by lfabbian         ###   ########.fr       */
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

/*
//draw point
void	draw_point(t_env *env)
{

}

//draw line
void	draw_line(t_env *env)
{
	while()
	{
		put_pixel();
	}
}*/
