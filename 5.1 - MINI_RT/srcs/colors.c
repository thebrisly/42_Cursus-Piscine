/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:16:20 by lfabbian          #+#    #+#             */
/*   Updated: 2023/08/14 15:19:57 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

t_color	int_to_rgb(const int r, const int g, const int b)
{
	t_color	rgb;

	rgb.r = r;
	rgb.g = g;
	rgb.b = b;
	return (rgb);
}

t_color	get_color(t_inter *inter)
{
	t_color	background;

	background.r = 0;
	background.g = 0;
	background.b = 0;
	if (inter->type == PLANE)
		inter->c = inter->obj.pl.color;
	else if (inter->type == SPHERE)
		inter->c = inter->obj.sp.color;
	else if (inter->type == CYLINDER)
		inter->c = inter->obj.cy.color;
	else
		inter->c = background;
	return (inter->c);
}

t_color	ambiance_color(t_color color, t_ambiant amb)
{
	t_color	ambient_color;

	ambient_color.r = color.r * amb.color.r * amb.ratio / 255.0;
	ambient_color.g = color.g * amb.color.g * amb.ratio / 255.0;
	ambient_color.b = color.b * amb.color.b * amb.ratio / 255.0;
	return (ambient_color);
}

t_color	shadow_color(t_color color, double shadow_intensity)
{
	t_color	shadow_color;

	shadow_color.r = color.r * shadow_intensity;
	shadow_color.g = color.g * shadow_intensity;
	shadow_color.b = color.b * shadow_intensity;
	return (shadow_color);
}

t_color	diffuse_color(t_inter *inter, t_light *light, t_color color)
{
	t_color	diffuse_color;
	t_v3d	light_dir;
	double	dot_product;
	double	diffuse_factor;

	light_dir = normalize(sub(light->coord, inter->point));
	dot_product = dot_product_v3d(inter->normal, light_dir);
	diffuse_factor = fmax(0.0, dot_product) * light->ratio;
	diffuse_color.r = fmin(inter->c.r * diffuse_factor, 255.0);
	diffuse_color.g = fmin(inter->c.g * diffuse_factor, 255.0);
	diffuse_color.b = fmin(inter->c.b * diffuse_factor, 255.0);
	color.r = fmin(color.r + diffuse_color.r, 255.0);
	color.g = fmin(color.g + diffuse_color.g, 255.0);
	color.b = fmin(color.b + diffuse_color.b, 255.0);
	return (color);
}
