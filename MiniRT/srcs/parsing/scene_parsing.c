/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:32:49 by lfabbian          #+#    #+#             */
/*   Updated: 2023/08/01 10:12:44 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minirt.h"

void	ambiance_parsing(char *line, t_rt *rt)
{
	int			i;
	char		**tab;
	t_ambiant	amb;

	i = 0;
	if (rt->sc->amb.id)
		print_error("Too many ambiance lights - 1 or 0 needed");
	tab = ft_split(line, ' ');
	if (!tab)
		print_error("Malloc failed");
	ft_bzero(&amb, sizeof(t_ambiant));
	amb.id = "A";
	if (count_elements(tab) != 3)
		print_error("wrong number of elements for ambiance");
	while (tab[++i])
	{
		if (i == 1)
			amb.ratio = parse_ratio(tab[i], amb.ratio);
		else if (i == 2)
			amb.color = parse_color(tab[i], amb.color);
	}
	rt->sc->amb = amb;
	free_tab(tab);
}

void	light_parsing(char *line, t_rt *rt)
{
	t_light	light;
	int		i;
	char	**tab;

	i = 0;
	if (rt->sc->light.id)
		print_error("Too many lights - 1 or 0 needed");
	tab = ft_split(line, ' ');
	if (!tab)
		print_error("Malloc failed");
	ft_bzero(&light, sizeof(t_light));
	light.id = "L";
	if (count_elements(tab) != 3)
		print_error("wrong number of elements for the light");
	while (tab[++i])
	{
		if (i == 1)
			light.coord = parse_coord(tab[i], light.coord);
		else if (i == 2)
			light.ratio = parse_ratio(tab[i], light.ratio);
	}
	rt->sc->light = light;
	free_tab(tab);
}

void	camera_parsing(char *line, t_rt *rt)
{
	t_camera	cam;
	char		**tab;
	int			i;

	i = 0;
	if (rt->sc->cam.id)
		print_error("Too many cameras - 1 or 0 needed");
	tab = ft_split(line, ' ');
	if (!tab)
		print_error("Malloc failed");
	ft_bzero(&cam, sizeof(t_camera));
	cam.id = "C";
	if (count_elements(tab) != 4)
		print_error("wrong number of elements for the camera");
	while (tab[++i])
	{
		if (i == 1)
			cam.coord = parse_coord(tab[i], cam.coord);
		else if (i == 2)
			cam.ori = parse_vector(tab[i], cam.ori);
		else if (i == 3)
			cam.fov = parse_other(tab[i], cam.fov, 1);
	}
	rt->sc->cam = cam;
	free_tab(tab);
}
