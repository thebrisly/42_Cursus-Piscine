/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:28:00 by lfabbian          #+#    #+#             */
/*   Updated: 2023/02/04 14:07:21 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_alg_help(t_init *s)
{
	ft_rotatea(s);
	ft_swapa(s);
	ft_reverse_rotatea(s);
}

void	push_up(t_init *s)
{
	if (s->small_i < (s->int_a / 2))
	{
		s->i = 0;
		while (s->i < s->small_i)
		{
			ft_rotatea(s);
			s->i++;
		}
	}
	else if (s->small_i >= (s->int_a / 2))
	{
		s->i = s->int_a;
		while (s->i > s->small_i)
		{
			ft_reverse_rotatea(s);
			s->i--;
		}
	}
}

void	find_smallest(t_init *s)
{
	s->i = 1;
	s->small_i = 0;
	s->min = s->pile_a[0];
	while (s->i < s->int_a)
	{
		if (s->pile_a[s->i] < s->min)
		{
			s->min = s->pile_a[s->i];
			s->small_i = s->i;
			s->i = 1;
		}
		s->i++;
	}
}
