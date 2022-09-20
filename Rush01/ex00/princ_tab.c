/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   princ_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:13:33 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/11 14:38:36 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

int	ft_inst(char *c)
{
	int	tab[4][4];
	int col;
	int line;
	int	i;
	int	compteur;

	compteur = 0;
	i = 0;
	line = 0;
	while (c[i] != '\0')
	{
		while (line < 4)
		{
			col = 0;
			while (col < 4)
			{
				if (i % 2 == 0 && (c[i] >= '1' && c[i] <= '4'))
				{
					tab[line][col] = c[i] - '0';
					printf("%i ", tab[line][col]);
					compteur++;
					i++;
					col++;
				}
				else if (c[i] == ' ' && (i % 2 > 0))
					i++;
				else
					return (1);
			}
			line++;
			printf("\n");
		}
	}
	if (compteur != 16)
		return (1);
}

int main(int argc, char **argv)
{
	int error;
	char	m_erreur[] = "Error encountered";

	error = 1;
	if (argc == 2)
		(ft_inst(argv[1]) == 1) mettre ca dans un if ensuite
			ft_putstr(m_erreur);
	else
		return (0);
}
