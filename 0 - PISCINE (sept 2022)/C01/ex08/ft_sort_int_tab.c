/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:42:03 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/05 10:29:06 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	c;

	i = 0;
	while (i < size)
	{		
		if (tab[i] > tab[i + 1])
		{
			c = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = c;
			i = 0;
		}
		else
			i++;
	}
}
/*int    main(void)
{
    int    tab[] = {1,52,62,41,7,95,38,152,65,2};
    int    x;

    x = 0;
    ft_sort_int_tab(tab, 10);
    while(x < 10)
    {
        printf("%d\n", tab[x]);
        x++;
    }
}*/
