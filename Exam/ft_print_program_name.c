/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:33:51 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/16 13:42:05 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void ft_putstr(char *c)
{
	int i;

	i= 0;
	while (c[i] != '\0')
	{
		write(1, &c[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	ft_putstr(argv[0]);
}
