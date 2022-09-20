/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:13:42 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/12 22:28:24 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	count;
	int	res;

	count = 1;
	res = nb;
	if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	else
	{
		while (count < nb)
		{
			res = res * (nb - count);
			count++;
		}
		return (res);
	}
}
/*#include <stdio.h>
int	main()
{
	int	number;
	int resultat;

	number = -45;
	resultat = ft_iterative_factorial(number);
	printf("La factorielle de %d est %d", number, resultat);
}*/
