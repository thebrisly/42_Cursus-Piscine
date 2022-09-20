/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:24:54 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/18 21:30:49 by rjuriens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	dict_error(void)
{
	ft_putstr("Dict Error\n");
	return (-10);
}

int	error(void)
{
	ft_putstr("Error\n");
	return (-10);
}

int	nb_toobig(void)
{
	ft_putstr("Provided number exeeds long long int MAX value !");
	return (-10);
}

int	check_nb_size(char *str)
{
	int		i;
	char	*s;

	i = 0;
	s = "18446744073709551615";
	if (ft_strlen(str) > 21)
		return (nb_toobig());
	else if (ft_strlen(str) == 21)
	{
		while (s[i])
		{
			if (str[i] > s[i])
			{
				return (nb_toobig());
			}
		}
	}
	return (1);
}
