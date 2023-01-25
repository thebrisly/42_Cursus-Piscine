/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:08:47 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/25 14:16:11 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_order(t_init *s)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (++i < s->int_a - 1)
	{
		while (s->pile_a[i] < s->pile_a[i + 1])
		{
			count++;
			i++;
		}
	}
	if (count == s->int_a - 1)
		return (1);
	else
		return (0);
}

void	check_errors(t_init *s)
{
	(void) s;
}

void	free_stacks(t_init *s)
{
	free(s->pile_a);
	free(s->pile_b);
	exit (1);
}
