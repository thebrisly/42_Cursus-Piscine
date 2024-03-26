/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:14:52 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/15 17:54:09 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_reverse_alphabet(char first)
{
	while (first >= 'a')
	{
		write(1, &first, 1);
		first--;
	}
}

int main(int argc, char **argv)
{
	ft_print_reverse_alphabet(*argv[1]);
}
