/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:28:00 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/29 14:33:58 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_smallest(t_init *s)
{
	if (s->counter_a == 3)
		ft_reverse_rotatea(s);
	else if (s->counter_a == 1)
		ft_rotatea(s);
	else if (s->counter_a == 2)
	{
		ft_rotatea(s);
		ft_rotatea(s);
	}
	s->counter_a = 0;
}
