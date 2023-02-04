/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:14:31 by lfabbian          #+#    #+#             */
/*   Updated: 2023/02/04 10:02:23 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* NOT USED NOW!


#include "push_swap.h"

void	sort_tab_get_median(t_init *s, int *tab, unsigned int size)
{
	unsigned int	i = 0;
	int				temp;

	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i+ 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	s->median = get_median(tab, size)
}

int	get_median(int *tab, int size)
{
	int	i;
	int	median;

	i = size / 2;
	if (size % 2 == 1)
		median = tab[i];
	else
	{
		i = (size / 2)
		median = tab[i] - 0.5;
	}
	return (median);
}*/
