/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:01:37 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/29 13:45:08 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_alg_help(t_init *s)
{
	ft_rotatea(s);
	ft_swapa(s);
	ft_reverse_rotatea(s);
}

void	create_stacks(t_init *ps)
{
	ps->pile_a = malloc(ps->int_a * sizeof(int));
	if (!ps->pile_a)
		error("Error [MALLOC]");
	ps->pile_b = malloc(ps->int_a * sizeof(int));
	if (!ps->pile_b)
		error("Error [MALLOC]");
}
