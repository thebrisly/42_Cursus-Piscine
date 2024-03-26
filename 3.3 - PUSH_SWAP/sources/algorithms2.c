/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:44:01 by lfabbian          #+#    #+#             */
/*   Updated: 2023/02/04 13:58:47 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_algorithm(t_init *s)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = s->int_a;
	while (((!check_order(s))))
	{
		j = 0;
		while (j < size && (!check_order(s)))
		{
			j++;
			if (((s->pile_a[0] >> i) & 1) == 0)
				ft_pushb(s);
			else
				ft_rotatea(s);
		}
		while (s->int_b > 0)
			ft_pusha(s);
		i++;
	}
}
