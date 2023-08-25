/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:50:40 by fabien            #+#    #+#             */
/*   Updated: 2023/08/16 09:47:13 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "minirt.h"

/* --------------------------------------------------- */
/* ----------- GLOBAL & USEFUL STRUCTURES ------------ */
/* --------------------------------------------------- */

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
}	t_color;

typedef struct s_v3d
{
	double	x;
	double	y;
	double	z;
}	t_v3d;

/* --------------------------------------------------- */
/* -------- STRUCTURES RELATED TO THE OBJECTS -------- */
/* --------------------------------------------------- */

typedef struct s_plane
{
	char	*id;
	t_v3d	coord;
	t_v3d	ori;
	t_color	color;
}	t_plane;

typedef struct s_sphere
{
	char	*id;
	t_v3d	coord;
	double	r;
	t_color	color;
}	t_sphere;

typedef struct s_cylinder
{
	char	*id;
	t_v3d	coord;
	t_v3d	norm_vec;
	double	r;
	double	h;
	t_color	color;

}	t_cylinder;

union			u_figures
{
	t_sphere	sp;
	t_plane		pl;
	t_cylinder	cy;
};

enum e_figure
{
	SPHERE,
	PLANE,
	CYLINDER
};

/* Linked list for all the objects in the scene */
typedef struct s_objects
{
	int					i;
	enum e_figure		type;
	union u_figures		fig;
	struct s_objects	*next;
}	t_objects;

/* --------------------------------------------------- */
/* --------- STRUCTURES RELATED TO THE SCENE --------- */
/* --------------------------------------------------- */

typedef struct s_ambiant
{
	char	*id;
	float	ratio;
	t_color	color;
}	t_ambiant;

typedef struct s_camera
{
	char	*id;
	double	fov;
	t_v3d	coord;
	t_v3d	ori;
}	t_camera;

typedef struct s_light
{
	char	*id;
	float	ratio;
	t_v3d	coord;
}	t_light;

/* A scene is defined by some objects,
two lights (ambiant & point of light) & one camera */
typedef struct s_scene
{
	t_ambiant	amb;
	t_camera	cam;
	t_light		light;
	t_objects	*obj;
}	t_scene;

/* struct for the image of mlbx */
typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

/* struct for everything mlbx related */
typedef struct s_mlbx
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
}	t_mlbx;

/* struct for intersections */
typedef struct s_inter
{
	int				i;
	enum e_figure	type;
	union u_figures	obj;
	double			dist;
	t_v3d			point;
	t_v3d			normal;
	t_color			c;
}	t_inter;

/* A single ray */
typedef struct s_ray
{
	t_v3d	v_dir;
	t_v3d	coord;
	t_inter	*inter;
}	t_ray;

/* --------------------------------------------------- */
/* ----------- MAIN STRUCTURE ------------------------ */
/* --------------------------------------------------- */

typedef struct s_rt
{
	int		win_w;
	int		win_h;
	t_mlbx	*mlbx;
	t_scene	*sc;
}	t_rt;

#endif
