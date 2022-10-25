/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 20:05:31 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/22 19:24:31 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int	check1(char *str, char a, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
	   if (str[i] == a)
		   return (0);
	   i++;
	}
	return (1);
}

int check2(char *str, char a)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == a)
			return (0);
		i++;
	}
	return (1);
}

void ft_union(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] != '\0')
	{
		if (check1(str1, str1[i], i) == 1)
			write(1, &str1[i], 1);
		i++;
	}
	i = 0;
	while (str2[i] != '\0')
	{
		if (check2(str1, str2[i]) == 1)
		{
			if (check1(str2, str2[i], i) == 1)
				write(1, &str2[i], 1);
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);	
	write(1, "\n", 1);
}
