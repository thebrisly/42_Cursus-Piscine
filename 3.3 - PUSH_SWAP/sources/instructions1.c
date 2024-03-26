/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:12:43 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/31 14:07:48 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Intervertit les 2 premiers éléments au sommet de la pile a.
Ne fait rien s’il n’y en a qu’un ou aucun */
void	ft_swapa(t_init *s)
{
	int	tmp;

	if (s->int_a > 1)
	{
		tmp = s->pile_a[0];
		s->pile_a[0] = s->pile_a[1];
		s->pile_a[1] = tmp;
		if (s->counter == 0)
			ft_printf("sa\n");
	}
}

/*Intervertit les 2 premiers éléments au sommet de la pile b.
Ne fait rien s’il n’y en a qu’un ou aucun */
void	ft_swapb(t_init *s)
{
	int	tmp;

	if (s->int_b > 1)
	{
		tmp = s->pile_b[0];
		s->pile_b[0] = s->pile_b[1];
		s->pile_b[1] = tmp;
		if (s->counter == 0)
			ft_printf("sb\n");
	}
}

/* ss : sa et sb en même temps.*/
void	ft_swaps(t_init	*s)
{
	s->counter = 1;
	ft_swapa(s);
	ft_swapb(s);
	ft_printf("ss\n");
	s->counter = 0;
}

/*Prend le premier élément au sommet de b et le met sur a.
Ne fait rien si b est vide.*/
void	ft_pusha(t_init *s)
{
	int	i_b;
	int	i_a;

	i_b = 0;
	if (s->int_b > 0)
	{
		s->int_a += 1;
		i_a = s->int_a;
		while (--i_a > 0)
			s->pile_a[i_a] = s->pile_a[i_a - 1];
		s->pile_a[i_a] = s->pile_b[i_a];
		s->int_b -= 1;
		i_b = s->int_b;
		while (i_a < i_b)
		{
			s->pile_b[i_a] = s->pile_b[i_a + 1];
			i_a++;
		}
		s->pile_b[i_a] = 0;
		ft_printf("pa\n");
	}
}

/* Prend le premier élément au sommet de a et le met sur b.
Ne fait rien si a est vide */
void	ft_pushb(t_init *s)
{
	int	i_a;
	int	i_b;

	i_a = 0;
	if (s->int_a > 0)
	{
		s->int_b += 1;
		i_b = s->int_b;
		while (--i_b > 0)
			s->pile_b[i_b] = s->pile_b[i_b - 1];
		s->pile_b[i_b] = s->pile_a[i_b];
		s->int_a -= 1;
		i_a = s->int_a;
		while (i_b < i_a)
		{
			s->pile_a[i_b] = s->pile_a[i_b + 1];
			i_b++;
		}
		s->pile_a[i_b] = 0;
		ft_printf("pb\n");
	}
}
