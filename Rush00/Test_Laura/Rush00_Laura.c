/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rush00_Laura.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:54:05 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/03 16:11:10 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


void	put_char(lettre)
{
	write(1, &lettre, 1);
}

void	ft_border(int a, int b)
{
	if (ligne == 1 && (colonne == 1 || colonne == x))
	{
		write(1,'A',1);
	}
	else if (position_x == 1 && position_y == 1)
	{
		write(1,'C',1);
	}

void	rush(int x, int y)
{
	int colonne;
	int ligne;

	colonne = 1;
	ligne = 1;
	while (ligne <= y)
	{
		while (colonne<= x)
		{
			ft_border(ligne, position_y);
			if ((ligne > 1 && ligne < x) && (colonne > 1 && colonne < x))
			{
				put_char(' ');
			}
			colonne++;
		}i
		write(1,"\n",1);
		ligne++;
	}		write(1,"\n",1);
        ligne++
}

int	main()
{
	rush(5,5);
	return (0);
}
