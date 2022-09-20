/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:09:37 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/15 17:14:30 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char first;

	first = 'a';
	while (first <= 'z')
	{
		write(1, &first, 1);
		first++;
	}
}

int	main()
{
	ft_print_alphabet();
}
