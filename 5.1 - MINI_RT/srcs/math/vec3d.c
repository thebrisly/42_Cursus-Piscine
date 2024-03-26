/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:43:05 by fabien            #+#    #+#             */
/*   Updated: 2023/08/15 18:43:14 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minirt.h"

/* returns a+b */
t_v3d	add(t_v3d a, t_v3d b)
{
	t_v3d	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	return (res);
}

/* returns a-b */
t_v3d	sub(t_v3d a, t_v3d b)
{
	t_v3d	res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return (res);
}

t_v3d	new_v3d(double x, double y, double z)
{
	t_v3d	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

/* multiplication by a scalar */
t_v3d	sc_mult(t_v3d a, double nb)
{
	t_v3d	res;

	res.x = a.x * nb;
	res.y = a.y * nb;
	res.z = a.z * nb;
	return (res);
}

/* returns ||a|| */
double	norme(t_v3d a)
{
	double	res;

	res = sqrt(pow(a.x, 2.0) + pow(a.y, 2.0) + pow(a.z, 2.0));
	return (res);
}
