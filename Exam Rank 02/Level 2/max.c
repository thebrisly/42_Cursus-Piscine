/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:30:09 by lfabbian          #+#    #+#             */
/*   Updated: 2022/12/18 14:42:00 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		max(int* tab, unsigned int len)
{
	int count = 0;
	int result = 0;
	int i = 0;
	if (len > 0)
	{
		while (count < len)
		{
			if (tab[i] > result)
				result = tab[i];
			i++;
			count++;
		}
		return (result);
	}
	return (0);
}

/*#include <stdio.h>

int main()
{
	int mark[] = {1, 3, 2, 10, 9};
	printf("%d", max(mark, 5));
}*/
