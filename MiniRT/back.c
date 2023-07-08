#include "../incs/minirt.h"

void	check_filename(char *file);
void	line_parsing(int fd, char *line, t_rt *rt);

int		ambiance_parsing(char *line, t_rt *rt);
int		light_parsing(char *line, t_rt *rt);
int		camera_parsing(char *line, t_rt *rt);

void	objects_parsing(char *line, t_rt *rt);
void	plane_parsing(char *line, t_rt *rt);
void	sphere_parsing(char *line, t_rt *rt);
void	cylinder_parsing(char *line, t_rt *rt);

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
	line_parsing(fd, line, rt);
	if (close (fd) == -1)
		print_error("Error while closing file");
}

void	line_parsing(int fd, char *line, t_rt *rt)
{
	char	**t;
	int		count[3];

	ft_memset(count, 0, sizeof(count));
	while (line)
	{
		free (line);
		t = ft_split(line, ' ');
		if (!t[0])
			continue ;
		else if (!cmp(t[0], "A"))
			count[0] = ambiance_parsing(line, rt);
		else if (!cmp(t[0], "C"))
			count[1] += camera_parsing(line, rt);
		else if (!cmp(t[0], "L"))
			count[2] += light_parsing(line, rt);
		else if ((!cmp(t[0], "pl")) || (!cmp(t[0], "sp")) || (!cmp(t[0], "cy")))
			objects_parsing(line, rt);
		else
			print_error("Something is not well defined");
		if (count[0] > 1 || count[1] > 1 || count[2] > 1)
			print_error("Too many cameras, lights or ambient lights");
		free(t);
		line = get_next_line(fd);
	}
}

void	check_filename(char *file)
{
	int	len;

	len = ft_strlen(file) - 1;
	if (!(file[len - 2] == '.' && file[len - 1] == 'r' && file[len] == 't'))
		print_error("Wrong scene format");
}


#include "../incs/minirt.h"

/* pl 	0,0,0		0,1.0,0		255,0,225 */
void	plane_parsing(char *line, t_rt *rt)
{
	(void) rt;
	(void) line;
}

/* sp 	0,0,20		20 			255,0,0 */
void	sphere_parsing(char *line, t_rt *rt)
{
	(void) rt;
	(void) line;
}

/* cy 	50.0,0.0,20.6	0,0,1.0	14.2	21.42	10,0,255 */
void	cylinder_parsing(char *line, t_rt *rt)
{
	(void) rt;
	(void) line;
}

void	objects_parsing(char *line, t_rt *rt)
{
	(void) rt;
	(void) line;
}

#include "../incs/minirt.h"

/* A 	0.2			255,255,255*/
int	ambiance_parsing(char *line, t_rt *rt)
{
	(void) line;
	(void) rt;
	return (1);
}

/* L 	-40,0,30	0.7 */
int	light_parsing(char *line, t_rt *rt)
{
	(void) line;
	(void) rt;
	return (1);
}

/* C 	-50,0,20	0,0,0 70 */
int	camera_parsing(char *line, t_rt *rt)
{
	(void) line;
	(void) rt;
	return (1);
}
