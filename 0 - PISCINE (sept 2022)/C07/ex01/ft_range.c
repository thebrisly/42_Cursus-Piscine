/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:22:17 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/15 10:31:55 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	len_nombres;
	int	i;

	i = 0;
	if (min >= max)
		return (0);
	len_nombres = max - min;
	tab = malloc(sizeof(int) * len_nombres);
	if (! tab)
		return (0);
	while (min < max)
	{
		tab[i] = min;
		min++;
		i++;
	}
	return (tab);
}

/*#include <stdio.h>
int	main()
{	
	int	minn;
	int maxx;
	int	res;

	minn = 10;
	maxx = 20;
	res = *ft_range(minn, maxx);
	printf("%d", res);
}*/
