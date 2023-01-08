/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:42:04 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/08 11:07:33 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ft_printf.h"
#include "libft.h"
#include <fcntl.h>
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

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}	vars;


//colors.c: color start, color end and curent percent on the slope
int		palette_one(double percent);
int		palette_two(double percent, int z);
int		palette_three(double percent);
int		palette_four(double percent);
int		palette_five(double percent);

//basics.c:
int ft_read_fd(char *file);
int env_init();

#endif
