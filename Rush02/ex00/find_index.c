/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:59:39 by saeby             #+#    #+#             */
/*   Updated: 2022/09/18 14:19:50 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	find_index(char *int_num, t_number *nums, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ft_strcmp(nums[i].int_num, int_num) == 0)
			return (i);
		i++;
	}	
	dict_error();
	return (-1);
}
