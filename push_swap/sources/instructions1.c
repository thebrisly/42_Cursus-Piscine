/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:12:43 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/24 10:15:52 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
Ne fait rien s’il n’y en a qu’un ou aucun.
sb (swap b ) : Intervertit les 2 premiers éléments au sommet de la pile b.
Ne fait rien s’il n’y en a qu’un ou aucun.
ss : sa et sb en même temps.
pa (push a) : Prend le premier élément au sommet de b et le met sur a.
Ne fait rien si b est vide.
pb (push b) : Prend le premier élément au sommet de a et le met sur b.
Ne fait rien si a est vide*/


//Intervertit les 2 premiers éléments au sommet de la pile a. Ne fait rien s’il n’y en a qu’un ou aucun.
void	ft_swapa(t_init *s)
{
	int    first_i;
	int    second_i;
	int    tmp;

	first_i = 0;
	second_i = 1;
	if (s->pile_a[second_i] && s->pile_a[first_i])
	{
		tmp = s->pile_a[first_i];
		s->pile_a[first_i] = s->pile_a[second_i];
		s->pile_a[second_i] = tmp;
		ft_printf("sa\n");
	}
}

//Intervertit les 2 premiers éléments au sommet de la pile b. Ne fait rien s’il n’y en a qu’un ou aucun.
void	ft_swapb(t_init *s)
{
	int    first_i;
	int    second_i;
	int    tmp;

	first_i = 0;
	second_i = 1;
	if (s->pile_b[second_i] && s->pile_b[first_i])
	{
		tmp = s->pile_b[first_i];
		s->pile_b[first_i] = s->pile_a[second_i];
		s->pile_b[second_i] = tmp;
		ft_printf("sb\n");
	}
}

// ss : sa et sb en même temps.
void	ft_swaps()
{
	ft_swapa;
	ft_swapb,
	//trouver un moyen de pas print sa et sb mais juste ss
}

//Prend le premier élément au sommet de b et le met sur a. Ne fait rien si b est vide.
void	ft_pusha()
{

}

//Prend le premier élément au sommet de a et le met sur b. Ne fait rien si a est vide
void	ft_pushb()
{

}
