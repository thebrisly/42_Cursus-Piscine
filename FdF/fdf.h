/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:42:04 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/08 15:06:53 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ft_printf.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#ifndef FDF_H
# define FDF_H

# define SHELL_RED "\033[0;31m"
# define SHELL_YELLOW "\033[0;33m"
# define SHELL_END_COLOR "\033[m"
# define TEXT_COLOR 0x1A1A1D
# define BACKGROUND 0x1A1A1D
# define MENU_BACKGROUND 0x950740
# define BLACK 0x000000
# define WHITE 0xFFFFFF

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define MLX_ERROR 1
# define ZOOM_FACTOR 1.1

typedef struct s_vector0 {
	int	x;
	int	y;
	int	z;
}	t_vector0;

typedef struct	s_env {
	void	*mlx;
	void	*win;
	void	*image;
	char	*address;
	char	*map_path;
	int		map_w;
	int		map_h;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		counter;
	float	zoom;
	float	alpha;
}	t_env;

//colors.c: color start, color end and curent percent on the slope
int		palette_one(double percent);
int		palette_two(double percent, int z);
int		palette_three(double percent);
int		palette_four(double percent);
int		palette_five(double percent);

//basics.c:
void map_info(t_env env, char *file);
int env_init(t_env env);

//hooks.c
void h_management(t_env base);
int esc_win(int key);
int close_win();

#endif
