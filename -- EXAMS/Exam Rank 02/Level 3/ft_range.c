/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:16:40 by brisly            #+#    #+#             */
/*   Updated: 2022/12/19 13:31:10 by brisly           ###   ########.fr       */
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
		tab[i] = start;
		start++;
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
	min = 5;
	max = 11;
	size = max - min;
	tab = ft_range(min, max);
	while(i <= size)
	{
		printf("%d, ", tab[i]);
		i++;
	}
}