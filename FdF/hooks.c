/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:17:24 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/20 08:48:55 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	h_management(t_env *env)
{
	mlx_key_hook(env->win, key_handler, env);
	mlx_hook(env->win, 17, 0, close_win, env);
	mlx_hook(env->win, 4, 0, mouse_handler, env);
	mlx_hook(env->win, 2, 1L << 0, key_handler, env);
}

int	key_handler(int key, t_env *env)
{
	if (key == 53)
		close_win(env);
	else if (key == 13 || key == 126)
		env->translation -= TRANS_FACTOR_X;
	else if (key == 1 || key == 125)
		env->translation += TRANS_FACTOR_X;
	else if (key == 0 || key == 123)
		env->alpha += 0.01;
	else if (key == 2 || key == 124)
		env->alpha -= 0.01;
	else if (key == 6)
		env->altitude += ALTITUDE;
	else if (key == 7)
		env->altitude -= ALTITUDE;
	return (0);
}

int	close_win(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	exit (0);
}

int	mouse_handler(int mousecode, int x, int y, t_env *env)
{
	(void) x;
	(void) y;
	if (mousecode == 4)
		env->scale *= ZOOM_FACTOR;
	else if (mousecode == 5)
		env->scale /= ZOOM_FACTOR;
	return (0);
}
