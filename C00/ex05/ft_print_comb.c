/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:37:04 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/21 09:04:19 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char value)
{
	write(1, &value, 1);
}

void	ft_result(char u, char d, char c)
{
	ft_putchar(c);
	ft_putchar(d);
	ft_putchar(u);
	if (! (c == '7' && d == '8' && u == '9'))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	char	u;
	char	d;
	char	c;

	c = '0';
	while (c <= '7')
	{
		d = c + 1;
		while (d <= '8')
		{
			u = d + 1;
			while (u <= '9')
			{
				ft_result(u, d, c);
				u++;
			}
			d++;
		}
		c++;
	}
}
/*#include <stdio.h>
int	main(void)
{
	ft_print_comb();
}*/
