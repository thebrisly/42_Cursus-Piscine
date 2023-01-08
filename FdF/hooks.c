/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:17:24 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/08 13:53:01 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	h_management(t_env env)
{
	mlx_key_hook(env.win, &esc_win, NULL);
	mlx_hook(env.win, 17, 0, &close_win, NULL);
	//mlx_key_hook(env.win, &key_callback, NULL);
	//mlx_mouse_hook(env.win, &key_callback, NULL);
}

int esc_win(int key)
{
    if (key == 53)
    {
        mlx_destroy_window(NULL, NULL);
		exit(0);
    }
    return (0);
}

int close_win()
{
    mlx_destroy_window(NULL, NULL);
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
