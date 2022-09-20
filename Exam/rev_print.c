/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:33:02 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/19 15:34:10 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int i;

	i  = 0;
	while (str[i] != '\0')
		i++;
	return(i);
}

char	*ft_rev_print(char *str)
{
	int d;

	d = ft_strlen(str) - 1;
	while (d >= 0)
	{
		write(1, &str[d], 1);
		d--;
	}
	return(str);
}

int main(int argc, char **argv)
{
	if (argc > 1)
		ft_rev_print(argv[1]);
	write(1, "\n", 1);
}
