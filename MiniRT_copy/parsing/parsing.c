#include "../incs/minirt.h"

void	file_parsing(char *file, t_rt *rt)
{
	int		fd;
	char	*line;

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
	line = clean_line(line);
	line_parsing(fd, line, rt);
	if (close (fd) == -1)
		print_error("Error while closing file");
}

void	line_parsing(int fd, char *line, t_rt *rt)
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
			objects_parsing(line, rt);
		else if (!ft_strncmp(line, "sp ", 3))
			objects_parsing(line, rt);
		else if (!ft_strncmp(line, "cy ", 3))
			objects_parsing(line, rt);
		else
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
