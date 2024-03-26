/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:25:40 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/20 10:09:37 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_env	env;

	env.alpha = 7.37;
	env.translation = 1;
	env.scale = 30;
	env.altitude = 1;
	env.y = 0;
	env.map_h = 0;
	env.map_w = 0;
	env.map_path = argv[1];
	if (argc == 2)
	{
		map_info(&env, env.map_path);
		check_format(&env, env.map_path);
		parse_map(&env, env.map_path);
		three_dim_point(&env);
		env_init(&env);
	}
	else
		error("Wrong number of args");
	while (1)
		;
}

int	error(char *error_message)
{
	ft_printf("%s\n", error_message);
	exit (1);
}

void	free_final_tab(t_env	*env)
{
	int	y;

	y = 0;
	while (y < env->map_h)
	{
		free(env->final_tab[y]);
		y++;
	}
	free(env->final_tab);
}
