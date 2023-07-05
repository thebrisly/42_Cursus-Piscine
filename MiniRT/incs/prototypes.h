#ifndef PROTOTYPES_H
# define PROTOTYPES_H
# include "minirt.h"

/* ERROR HANDLING */
int		print_error(char *error_message);

/* PARSING */
void    file_parsing(char *file, t_rt *rt);
int     count_elements(char *line);

/* MAKE WINDOW */
void	make_window(t_rt *rt);
void	my_mlx_pixel_put(t_img img, int x, int y, int color);

/* v3d */
t_v3d	add(t_v3d *a, t_v3d *b);
t_v3d	sub(t_v3d *a, t_v3d *b);
t_v3d	sc_mult(t_v3d *a, double nb);
double	norme(t_v3d *a);
t_v3d	cross(t_v3d *a, t_v3d *b);
t_v3d	normalize(t_v3d	*a);

/* UTILS 	*/
int		cmp(const char *s1, const char *s2);

#endif
