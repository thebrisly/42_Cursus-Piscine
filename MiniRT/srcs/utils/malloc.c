/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 09:32:38 by fgrasset          #+#    #+#             */
/*   Updated: 2023/08/16 09:43:17 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minirt.h"

t_inter	*calloc_utils(void)
{
	t_inter	*new;

	new = ft_calloc(sizeof(t_inter), 1);
	if (!new)
		print_error("There is an error of malloc \n");
	return (new);
}
