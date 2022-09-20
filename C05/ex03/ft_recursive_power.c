/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:56:46 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/12 11:42:37 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	res;

	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else
	{
		res = nb * ft_recursive_power(nb, power - 1);
		return (res);
	}
}
/*#include <stdio.h>
int	main()
{
	int nombre, puissance, r;

	nombre = -5;
	puissance = 3;
	r = ft_recursive_power(nombre, puissance);
	printf("%d a la puissance %d est egal a %d", nombre, puissance, r);
}*/
