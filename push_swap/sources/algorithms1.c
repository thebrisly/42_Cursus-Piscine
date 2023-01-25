/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:14:16 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/25 16:03:25 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//this file is for the algorithms

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
	else
		big_algorithm(s);
	free (s->pile_b);
}

void	two_args_alg(t_init *s)
{
	if (s->pile_a[0] > s->pile_a[1])
		ft_swapa(s);
}

void	three_int_alg(t_init *s) //3
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

void	four_int_alg(t_init *s) // not defined
{
	int	i;
	int	min;
	int	counter;

	i = 1;
	counter = 0;
	min = s->pile_a[i];
	while (i < 4)
	{
		if (s->pile_a[i] < min)
		{
			min = s->pile_a[i];
			counter = i;
			i = 1;
		}
		i++;
	}
	i = 0;
	while (i < counter)
	{
		ft_reverse_rotatea(s);
		i++;
	}
	ft_pushb(s);
	three_int_alg(s);
	ft_pusha(s);
}

void	five_int_alg(t_init *s) // 12
{
	(void) s;
}
