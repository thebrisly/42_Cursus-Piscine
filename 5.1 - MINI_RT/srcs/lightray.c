/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:41:18 by fabien            #+#    #+#             */
/*   Updated: 2023/08/16 09:39:41 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

void	inter_space(t_ray *ray, t_objects *objects, t_inter **intersection);
void	saving_space(double *max, t_inter	**closest_intersection, \
t_inter	*intersection, bool *is_in_shadow);

bool	inter_obj(t_rt *rt, t_ray *ray, double max)
{
	t_objects	*objects;
	t_inter		*close;
	t_inter		*inter;
	bool		is_in_shadow;

	objects = rt->sc->obj;
	close = calloc_utils();
	is_in_shadow = false;
	while (objects)
	{
		if (objects->i != ray->inter->i)
		{
			inter = NULL;
			inter_space(ray, objects, &inter);
			if (inter && inter->dist > E && inter->dist < max)
				saving_space(&max, &close, inter, &is_in_shadow);
			else
				free_inter(inter);
		}
		objects = objects->next;
	}
	if (close)
		ray->inter = close;
	return (is_in_shadow);
}

void	inter_space(t_ray *ray, t_objects *objects, t_inter **intersection)
{
	if (objects->type == PLANE)
		*intersection = intersect_plane(ray, &objects->fig.pl);
	else if (objects->type == SPHERE)
		*intersection = intersect_sphere(ray, &objects->fig.sp);
	else if (objects->type == CYLINDER)
		*intersection = intersect_cylinder(ray, &objects->fig.cy);
}

void	saving_space(double *max_distance, t_inter	**closest_intersection, \
t_inter	*intersection, bool *is_in_shadow)
{
	*max_distance = intersection->dist;
	free_inter(*closest_intersection);
	*closest_intersection = intersection;
	*is_in_shadow = true;
}

t_color	lights_shadows(t_rt *rt, t_scene *sc, t_inter *inter, t_color color)
{
	t_ray	to_light;
	t_color	final_color;
	bool	shad;

	final_color = ambiance_color(color, sc->amb);
	to_light.coord = inter->point;
	to_light.v_dir = normalize(sub(sc->light.coord, inter->point));
	shad = inter_obj(rt, &to_light, dst(&to_light.coord, &sc->light.coord));
	if (!shad)
		final_color = diffuse_color(inter, &sc->light, final_color);
	if (shad)
		final_color = shadow_color(final_color, 1);
	free_inter(to_light.inter);
	free_inter(inter);
	return (final_color);
}
