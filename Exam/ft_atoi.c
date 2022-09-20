/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:05:58 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/16 14:39:57 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int	ft_atoi(const char *str)
{
	int i;
	int atoi;
	int sign;

	i = 0;
	atoi = 0;
	sign = 1;
	
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0')
	{	
		atoi *= 10;
		atoi += str[i] - '0';
		i++;
	}
	return (atoi * sign);
}

int main()
{
	printf("%d\n", ft_atoi("543"));
}
