/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:43:26 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/16 13:53:54 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void ft_putstr(char *c)
{
	int i;

	i = 0;
	while (c[i] != '\0')
	{
		write(1, &c[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	int j;

	j = 1;
	while (j < argc)
	{
		ft_putstr(argv[j]);
		j++;
	}
}	
