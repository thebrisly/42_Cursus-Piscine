/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:00:18 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/20 20:04:04 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i_src;
	int		i_dest;
	char	*dest;

	i_src = 0;
	i_dest = 0;
	while (src[i_src])
		i_src++;
	dest = malloc((i_src + 1) * sizeof(char));
	if (!dest)
		return ("NULL");
	else
	{
		while (src[i_dest])
		{
			dest[i_dest] = src[i_dest];
			i_dest++;
		}
		dest[i_dest] = '\0';
		return (dest);
	}
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*stock;

	stock = 0;
	i = 0;
	stock = malloc(sizeof(t_stock_str) * (ac + 1));
	if (! stock)
		return (NULL);
	while (i < ac)
	{
		stock[i].size = ft_strlen(av[i]);
		stock[i].str = av[i];
		stock[i].copy = ft_strdup(av[i]);
		i++;
	}
	stock[i].size = 0;
	stock[i].str = 0;
	stock[i].copy = 0;
	return (stock);
}
/*#include <stdio.h>
int main(int argc, char **argv)
{
	t_stock_str *a;
	int	i;

	i = 0;
	a =ft_strs_to_tab(argc, argv);
	while (i < argc)
	{
		printf("%d, %s, %s\n", a[i].size, a[i].str, a[i].copy);
		i++;
	}
}*/
