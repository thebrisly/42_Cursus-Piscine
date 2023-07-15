#ifndef PROTOTYPES_H
# define PROTOTYPES_H
# include "minirt.h"

/* ERROR HANDLING */
int		print_error(char *error_message);

/* PARSING */
void    file_parsing(char *file, t_rt *rt);
char	*clean_line(char *line);
int     count_elements(char **tab);

int	is_float(char *str);
int is_color(char   *str);
int is_positive(char *str);
int is_range(float number);

float	s_to_f(char *str);
float   parse_ratio(char *str, float ratio);
t_color parse_color(char *line, t_color colors);
t_v3d   parse_coord(char *line, t_v3d points);
t_v3d   parse_vector(char *line, t_v3d points);

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

/* FREE */
void    free_structures(t_rt *rt);
void    free_tab(char **tab);

#endif
