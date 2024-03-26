/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2_vrai.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:40:21 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/21 09:05:35 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char value)
{
	write(1, &value, 1);
}

void	ft_write(int value)
{
	int	x;
	int	y;

	if (value > 9)
	{
		x = value / 10;
		y = value % 10;
		ft_putchar(x + '0');
		ft_putchar(y + '0');
	}
	else
	{
		ft_putchar('0');
		ft_putchar(value + 48);
	}
}

void	ft_result(int x, int y)
{
	ft_write(x);
	ft_putchar(' ');
	ft_write(y);
	if (x < 98 || y < 99)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int	x;
	int	y;

	x = 0 ;
	while (x <= 99)
	{
		y = x + 1;
		while (y <= 99)
		{
			ft_result(x, y);
			y++;
		}
		x++;
	}
}

/*int main()
{
	ft_print_comb2();
}*/
