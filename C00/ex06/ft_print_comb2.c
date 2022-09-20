/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2_vrai.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:40:21 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/20 10:35:27 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_numbers(int a, int b, int c, int d)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 2);
	write(1, &c, 1);
	write(1, &d, 1);
	if (a != '9' || b != '8' || c != '9' || d != '9')
		write (1, ", ", 2);
}

void	fr_print_comb2(void)
{
	int	tab[6];

	tab[0] = 1;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	tab[4] = 0;
	tab[5] = 0;
	if ((tab[0] <= 99 && tab[1] < 99))
	{
		while (tab[1] < 99)
		{
			while (tab[0] <= 99)
			{
				tab[2] = tab[0] / 10;
				tab[3] = tab[0] % 10;
				ft_numbers(tab[4] + 48, tab[5] + 48, tab[2] + 48, tab[3] + 48);
				tab[0]++;
			}
			tab[1]++;
			tab[4] = tab[1] / 10;
			tab[5] = tab[1] % 10;
			tab[0] = tab[1] + 1;
		}
	}
}

/*int    main(void)
{
    fr_print_comb2();
}*/
