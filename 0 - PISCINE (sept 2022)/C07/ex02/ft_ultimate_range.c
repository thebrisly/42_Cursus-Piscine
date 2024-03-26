/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:19:53 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/15 10:34:38 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len_nombres;
	int	i;

	i = 0;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	len_nombres = max - min;
	*range = malloc(sizeof(int) * len_nombres);
	if (! *range)
		return (-1);
	while (min < max)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (len_nombres);
}

/*#include <stdio.h>
int	main()
{
	int	minn;
	int maxx;
	int	*range;
	int res;

	minn = 10;
	maxx = 20;
	res = ft_ultimate_range(&range, minn, maxx);
	printf("%d", res);
}*/
