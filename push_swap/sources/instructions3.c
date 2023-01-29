/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:36:33 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/29 13:52:54 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Décale d’une position vers le bas tous les élements de la pile a.
Le dernier élément devient le premier.*/
void	ft_reverse_rotatea(t_init *s)
{
	int	tmp;
	int	i;

	i = s->int_a - 1;
	tmp = s->pile_a[i];
	while (i > 0)
	{
		s->pile_a[i] = s->pile_a[i - 1];
		i--;
	}
	s->pile_a[i] = tmp;
	if (s->counter == 0)
		ft_printf("rra\n");
}

/* Décale d’une position vers le bas tous les élements de la pile b.
Le dernier élément devient le premier. */
void	ft_reverse_rotateb(t_init *s)
{
	int	tmp;
	int	i;

	i = s->int_b - 1;
	tmp = s->pile_b[i];
	while (i > 0)
	{
		s->pile_b[i] = s->pile_b[i - 1];
		i--;
	}
	s->pile_b[i] = tmp;
	if (s->counter == 0)
		ft_printf("rra\n");
}

/*rrr : rra et rrb en même temps*/
void	ft_reverse_rotater(t_init *s)
{
	s->counter = 1;
	ft_reverse_rotatea(s);
	ft_reverse_rotateb(s);
	ft_printf("rrr\n");
	s->counter = 0;
}
