/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:00:59 by brisly            #+#    #+#             */
/*   Updated: 2023/07/16 21:40:01 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/minirt.h"

void print_objects(const t_objects *objects)
{
    const t_objects *current = objects;
    while (current != NULL)
    {
        /*if (&current->fig.pl != NULL)
        {	
            const t_plane *plane = &(current->fig.pl);
            printf("ID: %s\n", plane->id);
            printf("Coord: %f, %f, %f\n", plane->coord.x, plane->coord.y, plane->coord.z);
            printf("Orientation: %f, %f, %f\n", plane->ori.x, plane->ori.y, plane->ori.z);
            printf("Color: %d, %d, %d\n", plane->color.r, plane->color.g, plane->color.b);
        }*/
		if (&current->fig.sp != NULL)
        {	
            const t_sphere *sphere = &(current->fig.sp);
            printf("ID: %s\n", sphere->id);
            printf("Coord: %f, %f, %f\n", sphere->coord.x, sphere->coord.y, sphere->coord.z);
            printf("diameter: %f\n", sphere->d);
            printf("Color: %d, %d, %d\n", sphere->color.r, sphere->color.g, sphere->color.b);
        }
        current = current->next;
    }
}

int	main(int argc, char **argv)
{
	t_rt	*rt;

	(void) argv;
	rt = ft_calloc(sizeof(t_rt), 1);
	if (argc == 2)
	{
		file_parsing(argv[1], rt);
		/*printf("MAIN: %s ratio: %f\n", rt->sc->amb.id, rt->sc->amb.ratio);
		printf("MAIN: %s colors: %d, %d, %d\n",rt->sc->amb.id, rt->sc->amb.color.r, rt->sc->amb.color.g, rt->sc->amb.color.b);
		printf("MAIN: %s coord: %f, %f & %f\n", rt->sc->light.id, rt->sc->light.coord.x, rt->sc->light.coord.y, rt->sc->light.coord.z);
		printf("MAIN: %s ratio: %f\n",rt->sc->light.id, rt->sc->light.ratio);
		printf("MAIN: %s coord: %f, %f, %f\n", rt->sc->cam.id, rt->sc->cam.coord.x, rt->sc->cam.coord.y, rt->sc->cam.coord.z);
		printf("MAIN: %s ori: %f, %f, %f\n", rt->sc->cam.id, rt->sc->cam.ori.x, rt->sc->cam.ori.y, rt->sc->cam.ori.z);
		printf("MAIN: %s FOV: %f\n", rt->sc->cam.id, rt->sc->cam.fov);*/

		//print_objects(rt->sc->obj);
		printf("number of objects: %d\n", number_objects(rt->sc->obj));


		free_structures(rt);
	}
	else
	{
		ft_putstr_fd("\033[31m2 args needed :\n\033[0m", 2);
		ft_putstr_fd("\033[31m./miniRT [scene_path]\n\033[0m", 2);
	}
}