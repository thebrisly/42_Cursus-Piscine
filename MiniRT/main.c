/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:00:59 by brisly            #+#    #+#             */
/*   Updated: 2023/07/14 09:31:58 by brisly           ###   ########.fr       */
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
		//printf("MAIN: voici les couleurs de ambiant: %d, %d, %d\n", rt->sc->amb.color.r, rt->sc->amb.color.g, rt->sc->amb.color.b);
		free_structures(rt);
	}
	else
	{
		ft_putstr_fd("\033[31m2 args needed :\n\033[0m", 2);
		ft_putstr_fd("\033[31m./miniRT [scene_path]\n\033[0m", 2);
	}
}