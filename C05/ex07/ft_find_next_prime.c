/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:33:41 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/12 17:31:07 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	valeur_test;
	int	res;

	valeur_test = 1;
	if (nb > 1)
	{
		while (valeur_test < nb / 2)
		{
			++valeur_test;
			res = nb % valeur_test;
			if (res == 0)
				return (0);
		}
		return (1);
	}
	else
		return (2);
}

int	ft_find_next_prime(int nb)
{
	if (nb > 2147483629)
		return (2147483647);
	else
	{
		while (ft_is_prime(nb) != 1)
			nb++;
		return (nb);
	}		
}
/*#include <stdio.h>
int	main()
{
	int nombre, r;

	nombre = 42;
	r = ft_find_next_prime(nombre);
	printf("%d", r);
}*/
