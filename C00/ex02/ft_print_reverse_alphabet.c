/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:26:07 by lfabbian          #+#    #+#             */
/*   Updated: 2022/08/31 20:33:23 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	alphabet;

	alphabet = 'z';
	while (alphabet >= 'a')
	{
		write(1, &alphabet, 1);
		alphabet--;
	}
}

/*int main()
{
	ft_print_reverse_alphabet();
	return(0);
}*/
