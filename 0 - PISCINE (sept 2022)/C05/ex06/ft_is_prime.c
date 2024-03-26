/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:44:59 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/12 17:29:04 by lfabbian         ###   ########.fr       */
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
		return (0);
}

/*#include <stdio.h>
int	main()
{
	int nombre, r;

	nombre = 2147483647;
	r = ft_is_prime(nombre);
	printf("%d", r);
}*/
