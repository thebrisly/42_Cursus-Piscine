/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:14:16 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/24 14:50:12 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//this file is for the algorithms

void	algorithms(t_init *s)
{
	ft_reverse_rotatea(s);
	//ft_pushb(s);
	//ft_pushb(s);
	ft_rotater(s);
	ft_reverse_rotatea(s);
	ft_reverse_rotatea(s);
}
