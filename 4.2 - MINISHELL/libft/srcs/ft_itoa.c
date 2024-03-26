/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:41:52 by dferreir          #+#    #+#             */
/*   Updated: 2022/10/21 14:37:30 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	checker(char *str, int len)
{
	if (len == 0 && str[1] == 0)
		str[len] = '0';
	else if (len == 0 && str[1] != 0)
		str[len] = '-';
}

char	*ft_itoa(int n)
{
	char	*str;
	long	new_nbr;
	int		len;

	new_nbr = n;
	len = (new_nbr <= 0);
	while (n)
	{
		len++;
		n /= 10;
	}
	str = ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (0);
	str[len--] = 0;
	if (new_nbr < 0)
		new_nbr *= -1;
	while (new_nbr > 0)
	{
		str[len--] = new_nbr % 10 + '0';
		new_nbr /= 10;
	}
	checker(str, len);
	return (str);
}

/*int	main(int argc, char **argv)
{
	(void)argc;

	char *result = ft_itoa(atoi(argv[1]));
	if (result == argv[1])
		printf("it worked!");
	else
	{
		printf("%s\n", result);
		printf("%s\n", argv[1]);
		printf("nope");
	}
	return 0;
}*/
