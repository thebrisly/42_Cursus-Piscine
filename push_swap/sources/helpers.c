/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:01:37 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/31 09:55:47 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stacks(t_init *ps)
{
	ps->pile_a = malloc(ps->int_a * sizeof(int));
	if (!ps->pile_a)
		error("Error [MALLOC]");
	ps->pile_b = malloc(ps->int_a * sizeof(int));
	if (!ps->pile_b)
		error("Error [MALLOC]");
}
