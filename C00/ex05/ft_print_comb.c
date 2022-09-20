/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:37:04 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/19 18:17:22 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	int	c;
	int	d;
	int	u;

	c = '0';
	d = '1';
	u = '2';
	while (c <= '7')
	{
		while (d <= '8')
		{
			while (u <= '9')
			{
				write(1, &c, 1);
				write(1, &d, 1);
				write(1, &u, 1);
				if (c != '7')
					write(1, ",", 1);
				u++;
			}
			u = ++d + 1;
		}
		d = ++c;
	}
}
/*#include <stdio.h>
int	main(void)
{
	ft_print_comb();
}*/
