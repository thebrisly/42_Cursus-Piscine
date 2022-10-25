/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:10:43 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/03 00:00:02 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}
/*int	main(void)
{
	int a = 6;
	int b = 7;
	int *pa;
	int *pb;

	pa = &a;
	pb = &b;

	printf("La valeur de a est %d et la valeur de b est %d/n", a, b);

	ft_swap(&a, &b);
	printf("La valeur de a apres le swap est %d et la valeur de b est %d/n", a, b);
}*/
