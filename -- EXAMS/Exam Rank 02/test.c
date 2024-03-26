/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:51:31 by brisly            #+#    #+#             */
/*   Updated: 2023/02/20 09:49:57 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ft_putnbr(int number)
{
	if (number > 9)
		ft_putnbr(number/10);
	number = (number % 10) + 48;
	write(1, &number, 1);
}

int main(int argc, char **argv)
{
	int	number = argc - 1;
	(void) argv;

	ft_putnbr(number);
	write(1, "\n", 1);
}