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
	if (count_elements(tab) > 3)
		print_error("too many params");
	while (tab[++i])
	{
		if (i == 2)
			//
		if (i == 3)

		i++;
	}
	rt->sc->amb = amb;
}

/* L 	-40,0,30	0.7 */
void	light_parsing(char *line, t_rt *rt)
{
	t_light	light;

	if (rt->sc->light.id)
		print_error("Too many lights - 1 or 0 needed");
	ft_bzero(&light, sizeof(t_light));
	light.id = "L";

	rt->sc->light = light;
	(void) line;
}

/* C 	-50,0,20	0,0,0 70 */
void	camera_parsing(char *line, t_rt *rt)
{
	t_camera	cam;

	if (rt->sc->cam.id)
		print_error("Too many cameras - 1 or 0 needed");
	ft_bzero(&cam, sizeof(t_camera));
	cam.id = "C";

	rt->sc->cam = cam;
	(void) line;
}
