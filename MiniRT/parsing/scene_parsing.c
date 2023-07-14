#include "../incs/minirt.h"

/* A 	0.2			255,255,255*/
void	ambiance_parsing(char *line, t_rt *rt)
{
	int			i;
	char		**tab;
	t_ambiant	amb;

	i = 0;
	if (rt->sc->amb.id)
		print_error("Too many ambiance lights - 1 or 0 needed");
	tab = ft_split(line, ' '); 						//proteger malloc s'il me reste de la place mdr
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

/* L 	-40,0,30	0.7 */
void	light_parsing(char *line, t_rt *rt)
{
	t_light	light;
	//int	i;
	char **tab;

	//i = 0;
	if (rt->sc->light.id)
		print_error("Too many lights - 1 or 0 needed");
	tab = ft_split(line, ' ');
	ft_bzero(&light, sizeof(t_light));
	light.id = "L";
	if (count_elements(tab) != 3)
		print_error("wrong number of elements for the light");
	//boucle while
	rt->sc->light = light;
	free_tab(tab);
}

/* C 	-50,0,20	0,0,0 70 */
void	camera_parsing(char *line, t_rt *rt)
{
	t_camera	cam;
	char	**tab;
	//int	i;

	//i = 0;
	if (rt->sc->cam.id)
		print_error("Too many cameras - 1 or 0 needed");
	tab = ft_split(line, ' ');
	ft_bzero(&cam, sizeof(t_camera));
	cam.id = "C";
	if (count_elements(tab) != 4)
		print_error("wrong number of elements for the camera");
	//boucle while
	rt->sc->cam = cam;
	free_tab(tab);
}
