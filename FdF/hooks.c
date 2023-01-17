/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:17:24 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/17 15:29:48 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	h_management(t_env *env)
{
	mlx_key_hook(env->win, key_handler, env);
	mlx_hook(env->win, 17, 0, close_win, env);
	mlx_hook(env->win, 4, 0, mouse_handler, env);
	mlx_hook(env->win, 2, 1L << 0, key_handler, env);
	//mlx_key_hook(env.win, &key_callback, NULL);
	//mlx_mouse_hook(env.win, &key_callback, NULL);
}

int	key_handler(int key, t_env *env)
{
	if (key == 53)
		close_win(env);
	else if (key == 0 || key == 123 || key == 13 || key == 126)
		env->translation -= TRANS_FACTOR;
	else if (key == 2 || key == 124 || key == 1 || key == 125)
		env->translation += TRANS_FACTOR;
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
