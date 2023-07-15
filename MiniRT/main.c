/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:00:59 by brisly            #+#    #+#             */
/*   Updated: 2023/07/15 09:56:39 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/minirt.h"

int	main(int argc, char **argv)
{
	t_rt	*rt;

	(void) argv;
	rt = ft_calloc(sizeof(t_rt), 1);
	if (argc == 2)
	{
		file_parsing(argv[1], rt);
		printf("MAIN: %s ratio: %f\n", rt->sc->amb.id, rt->sc->amb.ratio);
		printf("MAIN: %s colors: %d, %d, %d\n",rt->sc->amb.id, rt->sc->amb.color.r, rt->sc->amb.color.g, rt->sc->amb.color.b);
		printf("MAIN: %s coord: %f, %f & %f\n", rt->sc->light.id, rt->sc->light.coord.x, rt->sc->light.coord.y, rt->sc->light.coord.z);
		printf("MAIN: %s ratio: %f\n",rt->sc->light.id, rt->sc->light.ratio);
		printf("MAIN: %s coord: %f, %f, %f\n", rt->sc->cam.id, rt->sc->cam.coord.x, rt->sc->cam.coord.y, rt->sc->cam.coord.z);
		printf("MAIN: %s coord: %f, %f, %f\n", rt->sc->cam.id, rt->sc->cam.ori.x, rt->sc->cam.ori.y, rt->sc->cam.ori.z);
		free_structures(rt);
	}
	else
	{
		ft_putstr_fd("\033[31m2 args needed :\n\033[0m", 2);
		ft_putstr_fd("\033[31m./miniRT [scene_path]\n\033[0m", 2);
	}
}