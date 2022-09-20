/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 20:05:31 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/19 21:41:11 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int	ft_check(char *str, char *l)
{

}

void	ft_union(char *str1, char *str2)
{
	int i;
	int j;
	int c;
	char dico[130];

	i = 0;
	c = 0;
	if (str[i] != dico[c])
		dico[c] = str[i];
	i++;
	c++;
	while (str1[i] != '\0')
	{
		while (dico[c] != '\0')
		}
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
}
