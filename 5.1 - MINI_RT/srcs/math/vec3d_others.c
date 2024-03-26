/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3d_others.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:43:01 by fabien            #+#    #+#             */
/*   Updated: 2023/08/15 18:43:02 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minirt.h"

/* returns axb (cross product) */
t_v3d	cross(t_v3d a, t_v3d b)
{
	t_v3d	res;

	res.x = a.y * b.z - a.z * b.y;
	res.y = a.z * b.x - a.x * b.z;
	res.z = a.x * b.y - a.y * b.x;
	return (res);
}

/* multiplies 2 vectors */
t_v3d	mult(t_v3d a, t_v3d b)
{
	t_v3d	res;

	res.x = a.x * b.x;
	res.y = a.y * b.y;
	res.z = a.z * b.z;
	return (res);
}

double	dot_product_v3d(t_v3d v1, t_v3d v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}
