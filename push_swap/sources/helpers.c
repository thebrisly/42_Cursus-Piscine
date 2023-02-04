/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:01:37 by lfabbian          #+#    #+#             */
/*   Updated: 2023/02/04 14:36:41 by lfabbian         ###   ########.fr       */
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


int	get_min(char **tab, int len)
{
	int	i;
	int min;
	int index;

	min = ft_atoi(tab[0]);
	i = 0;
	while (i < len)
	{
		if (tab[i][0] == 'a')
			i++;
		else if (ft_atoi(tab[i]) < min)
		{
			min = ft_atoi(tab[i]);
			index = i;
			i = 0;
			i++;
		}
		else
			i++;
	}
	tab[index][0] = 'a';
	return (index);
}
