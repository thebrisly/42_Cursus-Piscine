/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:01:37 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/27 15:44:43 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_alg_help(t_init *s)
{
	ft_rotatea(s);
	ft_swapa(s);
	ft_reverse_rotatea(s);
}

void	create_stacks(t_init *ps)
{
	ps->pile_a = malloc(ps->int_a * sizeof(int));
	if (!ps->pile_a)
		error("Error [MALLOC]");
	ps->pile_b = malloc(ps->int_a * sizeof(int));
	if (!ps->pile_b)
		error("Error [MALLOC]");
}

long	ft_atol(const char *str)
{
	int	i;
	long atol;
	int	sign;

	i = 0;
	atol = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		atol *= 10;
		atol += str[i] - 48;
		i++;
	}
	return (atol * sign);
}
