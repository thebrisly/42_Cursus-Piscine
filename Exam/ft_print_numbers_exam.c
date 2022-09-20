/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers_exam.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:01:44 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/19 13:03:43 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char c;

	c = '0';
	while (c <= '9')
	{
		write(1, &c, 1);
		c++;
	}
}

int main()
{
	ft_print_numbers();
}
