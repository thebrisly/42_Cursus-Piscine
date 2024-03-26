/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:42:57 by fabien            #+#    #+#             */
/*   Updated: 2023/08/15 18:42:58 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minirt.h"

/* calculates a quadratic equation and returns the result with
	the first intersection only in case of 2 intersections
	returns false if no result
	true if 1 or 2 results */
double	quad(double a, double b, double c)
{
	double	delta;
	double	t0;
	double	t1;

	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (-1);
	t0 = (-b - sqrt(delta)) / (2 * a);
	t1 = (-b + sqrt(delta)) / (2 * a);
	if (t0 < 0)
		t0 = t1;
	if (t0 < 0)
		return (-1);
	else if (t1 >= 0 && t1 < t0)
		return (t1);
	else
		return (t0);
}

/* returns the dot product of 2 vectors */
double	dot_product(t_v3d a, t_v3d b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

int	rgb_to_int(t_color rgb)
{
	return (((rgb.r & 0xff) << 16) | ((rgb.g & 0xff) << 8) | (rgb.b & 0xff));
}

double	dst(t_v3d *p1, t_v3d *p2)
{
	double	dx;
	double	dy;
	double	dz;

	dx = p2->x - p1->x;
	dy = p2->y - p1->y;
	dz = p2->z - p1->z;
	return (sqrt(dx * dx + dy * dy + dz * dz));
}
