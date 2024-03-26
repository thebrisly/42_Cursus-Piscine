/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fichier.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:47:04 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/20 11:55:50 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_point.h"
void set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}

int main(void)
{
	t_point	point;
	set_point(&point);
	printf("%d & %d", point.x, point.y);
	return(0);
}
