#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "../libft/libft.h"

# include "structures.h"

# define WIN_W 1200
# define WIN_H 800

/* main structure used for everything */
typedef struct s_rt
{
	int		win_w;
	int		win_h;
	t_mlbx	*mlbx;
	t_scene	*sc;
} t_rt;

# include "prototypes.h"

#endif
