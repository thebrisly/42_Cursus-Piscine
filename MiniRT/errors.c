/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:05:59 by brisly            #+#    #+#             */
/*   Updated: 2023/07/06 15:18:04 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

int	print_error(char *error_message)
{
	printf("\033[31m%s\033[30m\n", error_message);
	exit (EXIT_FAILURE);
}