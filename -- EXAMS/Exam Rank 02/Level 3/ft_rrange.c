/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:28:14 by brisly            #+#    #+#             */
/*   Updated: 2022/12/19 13:31:34 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     *ft_range(int start, int end)
{
	int i = 0;
	int *tab;
	int len;

	len = end - start + 1;
	tab = malloc (sizeof(int) * len);
	if (!tab || len < 1)
		return (NULL);
	while (start <= end)
	{
		tab[i] = end;
		end--;
		i++;
	}
	return (tab);
}

#include <stdio.h>

int main(void)
{
	int	min;
	int	max;
	int	*tab;
	int	i = 0;
	int	size;
	min = 1;
	max = 3;
	size = max - min;
	tab = ft_range(min, max);
	while(i <= size)
	{
		printf("%d, ", tab[i]);
		i++;
	}
}