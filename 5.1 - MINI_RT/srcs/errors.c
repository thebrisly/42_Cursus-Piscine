/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:41:44 by fabien            #+#    #+#             */
/*   Updated: 2023/08/16 10:00:41 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

int	print_error(char *error_message)
{
	ft_printf("\033[31mError\n%s\033[30m\n", error_message);
	exit (EXIT_FAILURE);
}
