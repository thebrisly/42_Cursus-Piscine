/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:07:03 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/03 11:00:59 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}
/*int	main()
{
	int div1;
	int mod1;

	div1 = 12;
	mod1 = 5;
	printf("Valeurs de div1 et mod1 avant: %d et %d \n", div1, mod1);
	ft_ultimate_div_mod(&div1, &mod1);
	printf("Valeurs de div1 et mod 1 apres: %d et %d \n", div1, mod1);
}*/
