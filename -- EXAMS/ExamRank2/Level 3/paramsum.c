/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:45:06 by brisly            #+#    #+#             */
/*   Updated: 2023/02/20 09:47:28 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n/10);
	n = (n % 10) + '0';
	write(1, &n, 1);
}

int main(int argc, char **argv)
{
	int	numbers = 0;
	(void) argv;
	numbers = argc -1;
	if (argc == 1)
		write(1, "0\n", 2);
	else
	{
		ft_putnbr(numbers);
		write(1, "\n", 1);
	}
}