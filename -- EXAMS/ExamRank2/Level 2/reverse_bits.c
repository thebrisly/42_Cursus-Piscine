/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:27:05 by lfabbian          #+#    #+#             */
/*   Updated: 2023/02/20 20:06:28 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	int i = 8;
	unsigned char res = 0;

	while (i > 0)
	{
		res = res * 2 +(octet % 2);
		octet = octet / 2;
		i--;
	}
	return (res);
}