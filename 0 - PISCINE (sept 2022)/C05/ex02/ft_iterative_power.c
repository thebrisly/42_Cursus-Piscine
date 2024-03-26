/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:05:23 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/08 13:50:10 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	compteur;
	int	resultat;

	compteur = 1;
	resultat = nb;
	if (power < 0)
		return (0);
	else if (power == 0 || (power == 0 && nb == 0))
		return (1);
	else
	{
		while (compteur < power)
		{
			resultat = nb * resultat;
			compteur++;
		}
		return (resultat);
	}
}
/*#include <stdio.h>
int	main()
{
	int nombre, puissance, f;

	nombre = -6;
	puissance = 7;
	f = ft_iterative_power(nombre, puissance);
	printf("%d a la puissance %d est egal a %d.", nombre, puissance, f);
}*/
