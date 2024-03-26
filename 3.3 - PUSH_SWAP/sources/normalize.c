/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:20:47 by lfabbian          #+#    #+#             */
/*   Updated: 2023/02/18 11:16:37 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_normalize(t_init *s)
{
	int		i;
	int		j;
	int		count;

	init_stack(s);
	i = -1;
	while (++i < s->int_a)
		s->tmp[i] = s->pile_a[i];
	i = 0;
	while (i < s->int_a)
	{
		j = -1;
		count = -1;
		while (++j < s->int_a)
		{
			if (s->tmp[i] < s->tmp[j])
				count++;
		}
		s->pile_a[i] = ((s->int_a - 1) - count);
		i++;
	}
	free (s->tmp);
}
