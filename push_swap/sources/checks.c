/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:08:47 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/27 16:00:01 by lfabbian         ###   ########.fr       */
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

void	check_max_min(int *tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_printf("ICI\n");
		printf("TEST: %i\n", tab[i]);
		if (tab[i] < -2147483648)
			error("Error\n");
		else if (tab[i] > 2147483647)
			error("Error\n");
		i++;
	}
}

void	check_non_num(char c)
{
	if (ft_isdigit(c) == 0)
		error("Error");;
}

int	check_double(t_init *s)
{
	(void) s;
	return 0;
}
