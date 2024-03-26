/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 10:26:29 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/08 12:04:45 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	int	r;

	if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	else
	{
		r = nb * ft_recursive_factorial(nb - 1);
		return (r);
	}
}
/*int	main()
{
	int nombre;

	nombre = 5;
	printf("%d",ft_recursive_factorial(nombre));
}*/
