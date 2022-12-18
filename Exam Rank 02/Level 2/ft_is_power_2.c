/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_power_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:56:58 by lfabbian          #+#    #+#             */
/*   Updated: 2022/12/18 14:08:13 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	    is_power_of_2(unsigned int n)
{
	int test;

	test = 1;
	while (test <= n)
	{
		if (test == n)
			return  (1);
		test = test * 2;
	}
	return (0);
}


#include <stdio.h>
int main()
{
	printf("%d", is_power_of_2(16));
}
