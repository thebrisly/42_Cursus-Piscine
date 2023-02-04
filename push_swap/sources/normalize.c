/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:20:47 by lfabbian          #+#    #+#             */
/*   Updated: 2023/02/04 14:32:43 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_normalize(t_init *s)
{
	int	size;
	int	i;
	int	index;
	char	**tmp;

	tmp = malloc(sizeof(char) * s->int_a);
	i = 0;
	size = s->int_a;
	while (i < size)
	{
		tmp[i] = ft_itoa(s->pile_a[i]);
		i++;
	}
	i = 0;
	while (i < size)
	{
		index = get_min(tmp, size);
		s->pile_a[index] = i;
		i++;
	}
	free (tmp);
}
