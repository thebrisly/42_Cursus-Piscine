/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:37:39 by lfabbian          #+#    #+#             */
/*   Updated: 2023/07/28 15:48:33 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minirt.h"

void	file_parsing(char *file, t_rt *rt)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error("File error");
	check_filename(file);
	line = get_next_line(fd);
	if (!line)
		print_error("Empty file");
	rt->sc = malloc(sizeof(t_scene));
	if (!rt->sc)
		print_error("Malloc error for scene");
	rt->sc->amb.id = 0;
	rt->sc->cam.id = 0;
	rt->sc->light.id = 0;
	line = clean_line(line);
	line_parsing(fd, line, rt, i);
	if (close (fd) == -1)
		print_error("Error while closing file");
}

void	line_parsing(int fd, char *line, t_rt *rt, int i)
{
	while (line)
	{
		if (!ft_strncmp(line, "A ", 2))
			ambiance_parsing(line, rt);
		else if (!ft_strncmp(line, "C ", 2))
			camera_parsing(line, rt);
		else if (!ft_strncmp(line, "L ", 2))
			light_parsing(line, rt);
		else if (!ft_strncmp(line, "pl ", 3))
			i = objects_parsing(line, rt, i);
		else if (!ft_strncmp(line, "sp ", 3))
			i = objects_parsing(line, rt, i);
		else if (!ft_strncmp(line, "cy ", 3))
			i = objects_parsing(line, rt, i);
		else if (!(line[0] == '\0'))
			print_error("A type is not well defined");
		free (line);
		line = get_next_line(fd);
		if (line)
			line = clean_line(line);
	}
	free (line);
}

void	check_filename(char *file)
{
	int	len;

	len = ft_strlen(file) - 1;
	if (!(file[len - 2] == '.' && file[len - 1] == 'r' && file[len] == 't'))
		print_error("Wrong scene format");
}
