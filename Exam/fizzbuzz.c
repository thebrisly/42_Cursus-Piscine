/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:04:35 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/19 14:32:46 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void ft_putnbr(int nbr)
{

	if (nbr > 9)
		ft_putnbr(nbr / 10);
	nbr = nbr % 10 + '0';
	write(1, &nbr, 1);
}

void ft_fb(int nbr)
{
	while (nbr <= 100)
	{
		if (nbr % 3 == 0 && nbr % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (nbr % 3 == 0)
			write(1, "fizz", 4);
		else if (nbr % 5 == 0)
			write(1, "buzz", 4);
		else
			ft_putnbr(nbr);
	  	write(1, "\n", 1);	//fonction qui tranforme les int en char.
		nbr++;
	}
}

int main()
{
	int n;

	n = 1;
	ft_fb(n);
}
