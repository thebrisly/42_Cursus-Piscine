/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:25:12 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/18 22:01:42 by rjuriens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	main(int argc, char **argv)
{
	t_number	*dict;

	if (argc == 2 && ft_is_numeric(argv[1]))
	{
		if (check_nb_size(argv[1]) < 0)
			return (0);
		dict = parse(DEFAULT_DICT);
		if (dict == NULL)
			return (dict_error());
		ft_putstr(ft_split_number(argv[1], dict, DEFAULT_DICT));
	}
	else if (argc == 3 && ft_is_numeric(argv[2]))
	{
		if (open(argv[1], O_RDONLY) == -1)
			return (error());
		if (check_nb_size(argv[2]) < 0)
			return (0);
		dict = parse(argv[1]);
		if (dict == NULL)
			return (dict_error());
		ft_putstr(ft_split_number(argv[2], dict, argv[1]));
	}
	else
		error();
}
