/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:25:40 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/08 15:25:18 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	t_env	env;

	env.map_path = argv[1];
	if (argc == 2)
	{
		map_info(env, env.map_path);
		//parse_map(fd);
		env_init(env);
	}
	else
		ft_printf("Wrong number of args");
}
