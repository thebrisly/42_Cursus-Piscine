/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:17:24 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/11 15:26:46 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	h_management(t_env *env)
{
	mlx_key_hook(env->win, &esc_win, &env);
	mlx_hook(env->win, 17, 0, &close_win, &env);
	//mlx_key_hook(env.win, &key_callback, NULL);
	//mlx_mouse_hook(env.win, &key_callback, NULL);
}

int esc_win(int key, t_env *env)
{
    if (key == 53)
    {
        mlx_destroy_window(env->mlx, env->win);
		exit(0);
    }
    return (0);
}

int close_win(t_env *env)
{
    mlx_destroy_window(env->mlx, env->win);
    exit(0);
}

/*int key_callback(int button)
{
	// Zoom avant
	if (button == KEY_PLUS || button == ON_MOUSEUP) //maybe ON_MOUSEUP
	{
		env.zoom *= ZOOM_FACTOR;
	}
	// Zoom arrière
	else if (button == KEY_MINUS || button == ON_MOUSEDOWN) //maybe: ON_MOUSEDOWN
		zoom /= ZOOM_FACTOR;
	return 0;
}*/
