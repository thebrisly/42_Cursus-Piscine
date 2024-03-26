/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:03:46 by lvon-war          #+#    #+#             */
<<<<<<< HEAD:ex00/ft_allocate.c
<<<<<<< HEAD
/*   Updated: 2022/09/10 17:40:59 by lfabbian         ###   ########.fr       */
=======
/*   Updated: 2022/09/10 17:48:33 by lvon-war         ###   ########.fr       */
>>>>>>> b8fdab108bc4da9797c34d9a9d7a9af8cfdfcbe1
=======
/*   Updated: 2022/09/10 23:47:55 by lvon-war         ###   ########.fr       */
>>>>>>> a96a24ea065ed5ceb8177651df4e8646c58dd406:ex00/allocate.c
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_allocateptr(int x)
{
	int	*ptr;
	int	i;

	ptr = (int *)malloc(4 * x);
	i = 0;
	while (i < x)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

int	**ft_allocatepptr(int x, int y)
{	
	int	**ptr;
	int	i;

	i = 0;
	ptr = (int **)malloc(8 * y);
	while (i < y)
	{
		ptr[i] = ft_allocateptr(x);
		i++;
	}
	return (ptr);
}
