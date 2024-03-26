/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:14:16 by lfabbian          #+#    #+#             */
/*   Updated: 2023/02/04 13:09:54 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithms(t_init *s)
{
	if (s->int_a == 2)
		two_args_alg(s);
	else if (s->int_a == 3)
		three_int_alg(s);
	else if (s->int_a == 4)
		four_int_alg(s);
	else if (s->int_a == 5)
		five_int_alg(s);
	else if (s->int_a >= 6)
		big_algorithm(s);
}

void	two_args_alg(t_init *s)
{
	if (s->pile_a[0] > s->pile_a[1])
		ft_swapa(s);
}

void	three_int_alg(t_init *s)
{
	if (s->pile_a[0] > s->pile_a[1])
	{
		if (s->pile_a[1] < s->pile_a[2])
		{
			if (s->pile_a[0] > s->pile_a[2])
				ft_rotatea(s);
			else
				ft_swapa(s);
		}
		else
		{
			ft_swapa(s);
			ft_reverse_rotatea(s);
		}
	}
	else
	{
		if (s->pile_a[0] > s->pile_a[2])
			ft_reverse_rotatea(s);
		else
			three_alg_help(s);
	}
}

void	four_int_alg(t_init *s)
{
	find_smallest(s);
	push_up(s);
	if (!check_order(s))
	{
		ft_pushb(s);
		three_int_alg(s);
		ft_pusha(s);
	}
}

void	five_int_alg(t_init *s)
{
	find_smallest(s);
	push_up(s);
	if (!check_order(s))
	{
		ft_pushb(s);
		four_int_alg(s);
		ft_pusha(s);
	}
}
