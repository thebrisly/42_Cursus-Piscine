/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 23:10:55 by lvon-war          #+#    #+#             */
/*   Updated: 2022/09/11 13:37:43 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_test_tab(int **board, int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			if (board[j][i] == 0)
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

void	ft_print(int **board, int x, int y)
{
	int		i;
	int		j;
	char	c;

	j = 0;
	write(1, "\n", 1);
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			c = board[j][i] + '0';
			i++;
			write(1, &c, 1);
		}
		write(1, "\n", 1);
		j++;
	}
	write(1, "\n", 1);
}