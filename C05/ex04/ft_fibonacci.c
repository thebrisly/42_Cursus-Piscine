/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:43:59 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/12 12:41:22 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int	res;

	if (index < 0)
		return (-1);
	else if (index == 0 || index == 1)
		return (index);
	else
	{
		res = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
		return (res);
	}
}
/*#include <stdio.h>
int	main()
{
	int number, r;

	number = -2;
	r = ft_fibonacci(number);
	printf("%d ", r);
}*/
