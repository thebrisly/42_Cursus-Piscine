/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:26:50 by lfabbian          #+#    #+#             */
/*   Updated: 2023/02/20 18:54:11 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void print_bits(unsigned char octet)
{
	int i = 8;
	unsigned char bit = 0;

	while (i--)
	{
		bit = (octet >> i & 1) + 48;
		write (1, &bit, 1);
	}
}


int main()
{
	unsigned char octet = 3;
	print_bits(octet);
}