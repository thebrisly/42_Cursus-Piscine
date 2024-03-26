/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:05:46 by fabien            #+#    #+#             */
/*   Updated: 2023/08/14 18:05:48 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

t_v3d	make_v_dir(t_rt *rt, double i, double j);
t_ray	make_ray(t_rt *rt, t_v3d v_dir);

double	dist(const t_v3d p1, const t_v3d p2)
{
	return (sqrt(pow(p2.x - p1.x, 2) + \
	pow(p2.y - p1.y, 2) + pow(p2.z - p1.z, 2)));
}

t_v3d	normalize(t_v3d a)
{
	double	length;

	length = dist(new_v3d(0, 0, 0), a);
	return (new_v3d(a.x / length, a.y / length, a.z / length));
}

/* creates all of the rays */
void	launch_rays(t_rt *rt)
{
	double	x;
	double	y;
	t_ray	ray;
	t_color	final_color;

	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
		{
			ray = make_ray(rt, make_v_dir(rt, x, y));
			ray.inter = closest_inter(rt, &ray);
			final_color = get_color(ray.inter);
			final_color = lights_shadows(rt, rt->sc, ray.inter, final_color);
			my_mlx_pixel_put(rt->mlbx->img, x, y, rgb_to_int(final_color));
		}
	}
}

t_ray	make_ray(t_rt *rt, t_v3d dir)
{
	t_ray	ray;

	ray.coord = rt->sc->cam.coord;
	ray.v_dir = dir;
	return (ray);
}

t_v3d	make_v_dir(t_rt *rt, double x, double y)
{
	t_v3d	v_dir;
	double	a;
	double	b;
	double	c;
	int		max;

	a = x + 0.5 - (WIN_W) * 0.5;
	b = y + 0.5 - (WIN_H) * 0.5;
	if (WIN_W > WIN_H)
		max = WIN_W;
	else
		max = WIN_H;
	c = max / (2 * tan((rt->sc->cam.fov * 0.5) * M_PI / 180.0));
	v_dir.x = 1 * a + 0 * b + 0 * c;
	v_dir.y = 0 * a + 1 * b + 0 * c;
	v_dir.z = 0 * a + 0 * b + 1 * c;
	return (normalize(v_dir));
}
