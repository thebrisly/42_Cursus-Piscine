/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:25:40 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/17 15:22:35 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_env	env;

	env.alpha = 0.5;
	env.translation = 15;
	env.map_path = argv[1];
	if (argc == 2)
	{
		map_info(&env, env.map_path);
		parse_map(&env, env.map_path);
		three_dim_point(&env);
		env_init(&env);
	}
	else
		error("Wrong number of args");
}

int	error(char *error_message)
{
	ft_printf("%s\n", error_message);
	exit (1);
}
