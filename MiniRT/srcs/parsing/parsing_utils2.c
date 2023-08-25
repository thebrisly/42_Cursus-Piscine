/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:35:52 by brisly            #+#    #+#             */
/*   Updated: 2023/07/17 13:31:00 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minirt.h"

float	parse_ratio(char *str, float ratio)
{
	if (!is_float(str))
		return (0.0);
	ratio = s_to_f(str);
	if (ratio >= 0 && ratio <= 1)
		return (ratio);
	else
	{
		print_error("wrong ratio");
		return (0);
	}
}

t_color	parse_color(char *line, t_color colors)
{
	char	**color;
	int		i;

	i = 0;
	color = ft_split(line, ',');
	if (!color)
		print_error("malloc in parse_color failed !");
	if (count_elements(color) != 3)
		print_error("element needs 3 colors (r,g,b)");
	while (color[i])
	{
		if (i == 0 && is_color(color[i]))
			colors.r = ft_atoi(color[i]);
		else if (i == 1 && is_color(color[i]))
			colors.g = ft_atoi(color[i]);
		else if (i == 2 && is_color(color[i]))
			colors.b = ft_atoi(color[i]);
		else
			print_error("somethin in colors failed");
		i++;
	}
	free_tab(color);
	return (colors);
}

t_v3d	parse_coord(char *line, t_v3d points)
{
	char	**point;
	int		i;

	i = 0;
	point = ft_split(line, ',');
	if (!point)
		print_error("malloc on parse_coord failed");
	if (count_elements(point) != 3)
		print_error("element needs 3 coordinates (x,y,z)");
	while (point[i])
	{
		if (i == 0 && is_float(point[i]))
			points.x = s_to_f(point[i]);
		else if (i == 1 && is_float(point[i]))
			points.y = s_to_f(point[i]);
		else if (i == 2 && is_float(point[i]))
			points.z = s_to_f(point[i]);
		else
			print_error("somethin in coordinates failed");
		i++;
	}
	free_tab(point);
	return (points);
}

t_v3d	parse_vector(char *line, t_v3d points)
{
	char	**point;
	int		i;
	float	tmp;

	i = 0;
	point = ft_split(line, ',');
	if (!point)
		print_error("malloc on parse_coord failed");
	if (count_elements(point) != 3)
		print_error("element needs 3 3d orientation (axis x,y,z)");
	while (point[i] && is_float(point[i]))
	{
		tmp = s_to_f(point[i]);
		if (i == 0 && is_range(tmp))
			points.x = tmp;
		else if (i == 1 && is_range(tmp))
			points.y = tmp;
		else if (i == 2 && is_range(tmp))
			points.z = tmp;
		else
			print_error("somethin in vecotr failed");
		i++;
	}
	free_tab(point);
	return (points);
}

float	parse_other(char *line, float element, int i)
{
	char	**tab;

	tab = ft_split(line, ',');
	if (count_elements(tab) != 1)
		print_error("wrong number of elements for parse_other");
	free_tab(tab);
	if (!is_float(line))
		print_error("number is not well written somewhere");
	element = s_to_f(line);
	if (i == 1 && is_float(line))
	{
		if (!(element >= 0 && element <= 180))
			print_error("FOV needs to be between 0 & 180");
	}
	else if (i == 2 && is_float(line))
	{
		if (element < 0)
			print_error("diameter or height must be bigger than 0");
	}
	return (element);
}
