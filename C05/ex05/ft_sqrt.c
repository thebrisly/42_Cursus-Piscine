/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:16:43 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/12 22:46:57 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	valeur_test;

	valeur_test = 1;
	if (nb <= 0)
		return (0);
	while (valeur_test * valeur_test < nb && valeur_test <= 46340)
		valeur_test++;
	if (valeur_test * valeur_test == nb)
		return (valeur_test);
	else
		return (0);
}
/*#include <stdio.h>
int	main()
{
	int nombre, r;

	nombre = 779135569;
	r = ft_sqrt(nombre);
	printf("%d", r);
}*/
