/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_plane_intersections.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:40:57 by fabien            #+#    #+#             */
/*   Updated: 2023/08/16 09:39:24 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

t_inter	*intersect_plane(t_ray *ray, t_plane *plane)
{
	t_inter	*inter;
	double	t;
	double	denom;

	inter = calloc_utils();
	plane->ori = normalize(plane->ori);
	denom = dot_product(plane->ori, ray->v_dir);
	if (fabs(denom) < 1e-6)
	{
		inter->dist = INFINITY;
		return (inter);
	}
	t = dot_product(sub(plane->coord, ray->coord), plane->ori) / denom;
	if (t < E)
	{
		inter->dist = INFINITY;
		return (inter);
	}
	inter->type = PLANE;
	inter->obj.pl = *plane;
	inter->dist = t;
	inter->point = add(ray->coord, sc_mult(ray->v_dir, t));
	inter->point = add(inter->point, sc_mult(inter->normal, E));
	inter->normal = plane->ori;
	return (inter);
}

t_inter	*intersect_sphere(t_ray *ray, t_sphere *sphere)
{
	t_inter	*inter;
	t_v3d	oc;
	double	t;

	inter = calloc_utils();
	oc = sub(ray->coord, sphere->coord);
	t = quad(dot_product(ray->v_dir, ray->v_dir), 2.0 * \
	dot_product(oc, ray->v_dir), dot_product(oc, oc) - sphere->r * sphere->r);
	if (t < 0)
	{
		inter->dist = INFINITY;
		return (inter);
	}
	inter->type = SPHERE;
	inter->obj.sp = *sphere;
	inter->dist = t;
	inter->point = add(ray->coord, sc_mult(ray->v_dir, t));
	inter->normal = normalize(sub(inter->point, sphere->coord));
	return (inter);
}
