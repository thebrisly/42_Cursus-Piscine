#include "../incs/minirt.h"

/* pl 	0,0,0		0,1.0,0		255,0,225 */
t_plane	plane_parsing(char *line, t_rt *rt)
{
	(void) rt;
	int			i;
	char		**tab;
	t_plane		plane;

	i = 0;
	tab = ft_split(line, ' '); 						//proteger malloc s'il me reste de la place mdr
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

t_sphere	sphere_parsing(char *line, t_rt *rt)
{
	(void) rt;
	int			i;
	char		**tab;
	t_sphere	sphere;

	i = 0;
	tab = ft_split(line, ' '); 						//proteger malloc s'il me reste de la place mdr
	ft_bzero(&sphere, sizeof(t_sphere));
	sphere.id = "sp";
	if (count_elements(tab) != 4)
		print_error("wrong number of elements for sphere");
	while (tab[++i])
	{
		if (i == 1)
			sphere.coord = parse_coord(tab[i], sphere.coord);
		else if (i == 2)
			sphere.d = parse_other(tab[i], sphere.d, 2);
		else if (i == 3)
			sphere.color = parse_color(tab[i], sphere.color);
	}
	free_tab(tab);
	return (sphere);
}

t_cylinder	cylinder_parsing(char *line, t_rt *rt)
{
	(void) rt;
	int			i;
	char		**tab;
	t_cylinder	cylinder;

	i = 0;
	tab = ft_split(line, ' '); 						//proteger malloc s'il me reste de la place mdr
	ft_bzero(&cylinder, sizeof(t_cylinder));
	cylinder.id = "sp";
	if (count_elements(tab) != 6)
		print_error("wrong number of elements for cylinder");
	while (tab[++i])
	{
		if (i == 1)
			cylinder.coord = parse_coord(tab[i], cylinder.coord);
		else if (i == 2)
			cylinder.norm_vec = parse_vector(tab[i], cylinder.norm_vec);
		else if (i == 3)
			cylinder.d = parse_other(tab[i], cylinder.d, 2);
		else if (i == 4)
			cylinder.h = parse_other(tab[i], cylinder.h, 2);
		else if (i == 5)
			cylinder.color = parse_color(tab[i], cylinder.color);
	}
	free_tab(tab);
	return (cylinder);
}

void	objects_parsing(char *line, t_rt *rt) //ajout dans liste chainee ??
{
	t_objects *new_object;
	
	new_object = malloc(sizeof(t_objects));
	if (!new_object)
		print_error("malloc for new object failed");
	if (!ft_strncmp(line, "pl ", 3))
		new_object->fig.pl = plane_parsing(line, rt);
	else if (!ft_strncmp(line, "sp ", 3))
		new_object->fig.sp = sphere_parsing(line, rt);
	else if (!ft_strncmp(line, "cy ", 3))
		new_object->fig.cy = cylinder_parsing(line, rt);
	new_object->next = NULL;
	object_add_end(&rt->sc->obj, new_object);
}
