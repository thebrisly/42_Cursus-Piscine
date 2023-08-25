/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:41:23 by fabien            #+#    #+#             */
/*   Updated: 2023/08/16 09:35:18 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

int	is_closest(t_inter *closest, t_inter *temp);

/* retruns the closest intersection in the ray */
t_inter	*closest_inter(t_rt *rt, t_ray *ray)
{
	t_inter		*closest;
	t_inter		*temp;
	t_objects	*curr_fig;

	closest = calloc_utils();
	closest->dist = INFINITY;
	curr_fig = rt->sc->obj;
	while (curr_fig)
	{
		closest->i = curr_fig->i;
		if (curr_fig->type == PLANE)
			temp = intersect_plane(ray, &curr_fig->fig.pl);
		else if (curr_fig->type == SPHERE)
			temp = intersect_sphere(ray, &curr_fig->fig.sp);
		else if (curr_fig->type == CYLINDER)
			temp = intersect_cylinder(ray, &curr_fig->fig.cy);
		if (closest && temp->dist > 0 && is_closest(closest, temp))
			free_inter(closest);
		if (closest && temp->dist > 0 && is_closest(closest, temp))
			closest = temp;
		else
			free_inter(temp);
		curr_fig = curr_fig->next;
	}
	return (closest);
}

int	is_closest(t_inter *closest, t_inter *temp)
{
	if (temp->dist == INFINITY && closest->dist)
		return (0);
	if (temp->dist < closest->dist)
		return (1);
	return (0);
}
