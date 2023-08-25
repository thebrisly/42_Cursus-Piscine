/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:38:22 by lfabbian          #+#    #+#             */
/*   Updated: 2023/08/14 09:57:42 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minirt.h"

t_plane	plane_parsing(char *line)
{
	int			i;
	char		**tab;
	t_plane		plane;

	i = 0;
	tab = ft_split(line, ' ');
	ft_bzero(&plane, sizeof(t_plane));
	plane.id = "pl";
	if (count_elements(tab) != 4)
		print_error("wrong number of elements for plane");
	while (tab[++i])
	{
		if (i == 1)
			plane.coord = parse_coord(tab[i], plane.coord);
		else if (i == 2)
			plane.ori = parse_vector(tab[i], plane.ori);
		else if (i == 3)
			plane.color = parse_color(tab[i], plane.color);
	}
	free_tab(tab);
	return (plane);
}

t_sphere	sphere_parsing(char *line)
{
	int			i;
	char		**tab;
	t_sphere	sphere;

	i = 0;
	tab = ft_split(line, ' ');
	ft_bzero(&sphere, sizeof(t_sphere));
	sphere.id = "sp";
	if (count_elements(tab) != 4)
		print_error("wrong number of elements for sphere");
	while (tab[++i])
	{
		if (i == 1)
			sphere.coord = parse_coord(tab[i], sphere.coord);
		else if (i == 2)
			sphere.r = parse_other(tab[i], sphere.r, 2) / 2;
		else if (i == 3)
			sphere.color = parse_color(tab[i], sphere.color);
	}
	free_tab(tab);
	return (sphere);
}

t_cylinder	cylinder_parsing(char *line)
{
	int			i;
	char		**tab;
	t_cylinder	cylinder;

	i = 0;
	tab = ft_split(line, ' ');
	ft_bzero(&cylinder, sizeof(t_cylinder));
	cylinder.id = "cy";
	if (count_elements(tab) != 6)
		print_error("wrong number of elements for cylinder");
	while (tab[++i])
	{
		if (i == 1)
			cylinder.coord = parse_coord(tab[i], cylinder.coord);
		else if (i == 2)
			cylinder.norm_vec = parse_vector(tab[i], cylinder.norm_vec);
		else if (i == 3)
			cylinder.r = parse_other(tab[i], cylinder.r, 2) / 2;
		else if (i == 4)
			cylinder.h = parse_other(tab[i], cylinder.h, 2);
		else if (i == 5)
			cylinder.color = parse_color(tab[i], cylinder.color);
	}
	free_tab(tab);
	return (cylinder);
}

int	objects_parsing(char *line, t_rt *rt, int i)
{
	t_objects	*new_object;

	new_object = ft_calloc(sizeof(t_objects), 1);
	if (!new_object)
		print_error("malloc for new object failed");
	if (!ft_strncmp(line, "pl ", 3))
	{
		new_object->type = PLANE;
		new_object->fig.pl = plane_parsing(line);
	}
	else if (!ft_strncmp(line, "sp ", 3))
	{
		new_object->type = SPHERE;
		new_object->fig.sp = sphere_parsing(line);
	}
	else if (!ft_strncmp(line, "cy ", 3))
	{
		new_object->type = CYLINDER;
		new_object->fig.cy = cylinder_parsing(line);
	}
	new_object->i = i;
	i = i + 1;
	new_object->next = NULL;
	object_add_end(&rt->sc->obj, new_object);
	return (i);
}
