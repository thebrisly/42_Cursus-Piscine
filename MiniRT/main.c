/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:00:59 by brisly            #+#    #+#             */
/*   Updated: 2023/07/06 15:32:00 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/minirt.h"

int	main(int argc, char **argv)
{
	t_rt	*rt;

	(void) argv;
	rt = malloc(sizeof(t_rt));
	if (argc == 2)
	{
		file_parsing(argv[1], rt);
		free (rt);
		free (rt->sc);
	}
	else
		print_error("2 args needed");
}