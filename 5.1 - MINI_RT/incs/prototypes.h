/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:52:24 by fabien            #+#    #+#             */
/*   Updated: 2023/08/16 09:35:05 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H
# include "minirt.h"

/* ERROR HANDLING */
int			print_error(char *error_message);

/* PARSING */
void		file_parsing(char *file, t_rt *rt);
char		*clean_line(char *line);
int			count_elements(char **tab);
void		check_filename(char *file);
void		line_parsing(int fd, char *line, t_rt *rt, int i);
void		ambiance_parsing(char *line, t_rt *rt);
void		light_parsing(char *line, t_rt *rt);
void		camera_parsing(char *line, t_rt *rt);
int			objects_parsing(char *line, t_rt *rt, int i);
t_objects	*last_object(t_objects	*lst);
void		object_add_end(t_objects **lst, t_objects *new);
int			number_objects(t_objects *lst);
int			is_float(char *str);
bool		is_color(char *str);
int			is_positive(char *str);
int			is_range(float number);
float		s_to_f(char *str);
float		parse_ratio(char *str, float ratio);
t_color		parse_color(char *line, t_color colors);
t_v3d		parse_coord(char *line, t_v3d points);
t_v3d		parse_vector(char *line, t_v3d points);
float		parse_other(char *line, float element, int i);

/* MAKE WINDOW */
void		make_window(t_rt *rt);
void		my_mlx_pixel_put(t_img img, int x, int y, int color);

/* RAYS */
void		launch_rays(t_rt *rt);
t_inter		*closest_inter(t_rt *rt, t_ray *ray);
t_inter		*intersect_plane(t_ray *ray, t_plane *plane);
t_inter		*intersect_sphere(t_ray *ray, t_sphere *sphere);
t_inter		*intersect_cylinder(t_ray *ray, t_cylinder *cylinder);

/* v3d */
t_v3d		new_v3d(double x, double y, double z);
t_v3d		add(t_v3d a, t_v3d b);
t_v3d		sub(t_v3d a, t_v3d b);
t_v3d		sc_mult(t_v3d a, double nb);
double		norme(t_v3d a);
double		dot_product_v3d(t_v3d v1, t_v3d v2);
t_v3d		cross(t_v3d a, t_v3d b);
t_v3d		normalize(t_v3d	a);
t_v3d		mult(t_v3d a, t_v3d b);

/* MATH */
double		quad(double a, double b, double c);
double		dot_product(t_v3d a, t_v3d b);
double		dst(t_v3d *p1, t_v3d *p2);
int			rgb_to_int(t_color rgb);
double		dist(const t_v3d p1, const t_v3d p2);

/* LIGHTRAY & COLORS */
t_color		int_to_rgb(const int r, const int g, const int b);
t_color		get_color(t_inter *inter);
t_color		lights_shadows(t_rt *rt, t_scene *sc, \
t_inter *inter, t_color color);
t_color		ambiance_color(t_color color, t_ambiant amb);
t_color		shadow_color(t_color color, double shadow_intensity);
t_color		diffuse_color(t_inter *inter, t_light *light, t_color color);

/* UTILS */
int			cmp(const char *s1, const char *s2);
void		print_v3d(t_v3d vect);
void		print_inter(t_inter *inter);
t_inter		*calloc_utils(void);

/* FREE */
void		free_tab(char **tab);
void		free_objects(t_rt *rt);
void		free_inter(t_inter *inter);
void		free_rt(t_rt *rt);

#endif
