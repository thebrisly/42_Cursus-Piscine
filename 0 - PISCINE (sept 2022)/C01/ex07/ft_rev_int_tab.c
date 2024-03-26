/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:09:22 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/05 09:33:31 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	changement;
	int	fin;

	fin = size - 1;
	i = 0;
	while (i < (size / 2))
	{
		changement = tab[i];
		tab[i] = tab[fin];
		tab[fin] = changement;
		i++;
		fin--;
	}
}

/*int	main(void)
{
	int	tab[] = {1,2,3,4,7,7,3,1,9};
	int x;
	int size;

	size = 9;
	x = 0;

	ft_rev_int_tab(tab, size);

	while (x < size)
    {
	   	printf("%d", tab[x]);
		x++;
    }
}*/
