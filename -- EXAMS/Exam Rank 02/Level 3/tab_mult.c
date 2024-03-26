/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:42:18 by brisly            #+#    #+#             */
/*   Updated: 2023/02/20 21:43:48 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


void			ft_putnbr(int n)
{
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

int				ft_atoi(char *s)
{
	int		num;
	int		sign;

	sign = 1;
	num = 0;
	while (*s == '\t' || *s == '\n' || *s == '\v' || \
			*s == '\f' || *s == '\r' || *s == ' ')
		s++;
	if (*s == '-')
		sign = -1;
	while ((*s == '-') || (*s == '+'))
		s++;
	while (*s && *s >= '0' && *s <= '9')
		num = (num * 10) + ((int)(*(s++)) - '0');
	return (num * sign);
}

void	ft_tabmult(int nbr)
{
	int		i;

	i = 1;
	while (i <= 9)
	{
		ft_putnbr(i);
		ft_putchar('x');
		ft_putnbr(nbr);
		
		ft_putchar(' ');
		ft_putchar('=');
		ft_putchar(' ');

		ft_putnbr(i * nbr);
		ft_putchar('\n');
		i++;
	}
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		ft_tabmult(ft_atoi(argv[1]));
	else
		ft_putchar('\n');
	return (0);
}