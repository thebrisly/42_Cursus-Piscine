/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 10:12:14 by dferreir          #+#    #+#             */
/*   Updated: 2022/10/20 11:26:52 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	final;
	int	i;
	int	sign;

	final = 0;
	i = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		++i;
	}
	if (str[i] == '-' || str[i] == '+')
		return (0);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		final *= 10;
		final += str[i] - '0';
		++i;
	}
	return (final * sign);
}

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("Atoi: %d\n", atoi(argv[1]));
	printf("Ft_Atoi: %d", ft_atoi(argv[1]));

	return (0);
}*/
