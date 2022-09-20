/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:27:32 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/04 19:57:12 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_if(int col, int line, int x, int y)
{
	if (line == 1 || line == y)
	{
		if (col == 1 || col == x)
		{
			if (line == 1)
				ft_putchar('A');
			else if (line == y && line != 1)
				ft_putchar('C');
		}
		else
			ft_putchar('B');
	}
	else
	{
		if (col == 1 || col == x)
			ft_putchar('B');
		else
			ft_putchar(' ');
	}
}

void	rush02(int y, int x)
{
	int	col;
	int	line;

	line = 1;
	while (line <= y && x >= 0 && y >= 0)
	{
		col = 1;
		while (col <= x)
		{
			ft_if(col, line, x, y);
			col++;
		}
		ft_putchar('\n');
		line++;
	}
}
