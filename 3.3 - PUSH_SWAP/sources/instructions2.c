/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:14:07 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/31 14:04:41 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Décale d’une position vers le haut tous les élements de la pile a.
Le premier élément devient le dernier. */
void	ft_rotatea(t_init *s)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = s->pile_a[i];
	while (i < s->int_a - 1)
	{
		s->pile_a[i] = s->pile_a[i + 1];
		i++;
	}
	s->pile_a[i] = tmp;
	if (s->counter == 0)
		ft_printf("ra\n");
}

/* Décale d’une position vers le haut tous les élements de la pile b.
Le premier élément devient le dernier. */
void	ft_rotateb(t_init *s)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = s->pile_b[i];
	while (i < s->int_b - 1)
	{
		s->pile_b[i] = s->pile_b[i + 1];
		i++;
	}
	s->pile_b[i] = tmp;
	if (s->counter == 0)
		ft_printf("rb\n");
}

/*rr : ra et rb en même temps.*/
void	ft_rotater(t_init *s)
{
	s->counter = 1;
	ft_rotatea(s);
	ft_rotateb(s);
	ft_printf("rr\n");
	s->counter = 0;
}
