/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_exam.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:52:24 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/19 18:10:58 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int i;
	int sign;
	int atoi;

	i = 0;
	sign = 1;
	atoi = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		atoi *= 10;
		atoi += str[i] - '0';
		i++;
	}
	return(atoi * sign);
}

#include <stdio.h>
int main()
{
	printf("%d", ft_atoi("574493"));
}
