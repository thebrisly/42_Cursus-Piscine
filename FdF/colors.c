/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:41:29 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/03 16:03:48 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	palette_one(double percent)
{
	if (percent < 0.2)
		return (0x9A1F6A);
	else if (percent < 0.4)
		return (0xC2294E);
	else if (percent < 0.6)
		return (0xEC4B27);
	else if (percent < 0.8)
		return (0xEF8633);
	else
		return (0xF3AF3D);
}

int	palette_two(double percent, int z)
{
	(void)percent;
	if (z <= -5)
		return (0x003366);
	if (z <= -2)
		return (0x1962E1);
	else if (z <= 0)
		return (0x99CCFF);
	else if (z <= 8)
		return (0x009A00);
	else if (z <= 20)
		return (0xFFB266);
	else if (z <= 25)
		return (0xC16100);
	else if (z >= 30)
		return (0x945700);
	else if (z <= 40)
		return (0x693502);
	else
		return (0xFFFFFF);
}

int	palette_three(double percent)
{
	if (percent < 0.1)
		return (0x277DA1);
	else if (percent < 0.2)
		return (0x577590);
	else if (percent < 0.3)
		return (0x4D908E);
	else if (percent < 0.4)
		return (0x43AA8B);
	else if (percent < 0.5)
		return (0x90BE6D);
	else if (percent < 0.6)
		return (0xF9C74F);
	else if (percent < 0.7)
		return (0xF9844A);
	else if (percent < 0.8)
		return (0xF8961E);
	else if (percent < 0.9)
		return (0xF3722C);
	else
		return (0xF94144);
}

int	palette_four(double percent)
{
	if (percent < 0.2)
		return (0x5F0F40);
	else if (percent < 0.4)
		return (0x9A031E);
	else if (percent < 0.6)
		return (0xFB8B24);
	else if (percent < 0.8)
		return (0xE36414);
	else
		return (0x0F4C5C);
}

int	palette_five(double percent)
{
	if (percent < 0.1)
		return (0x4D1A7F);
	else if (percent < 0.3)
		return (0xCC99FF);
	else if (percent < 0.5)
		return (0xEDBDFF);
	else if (percent < 0.6)
		return (0xFFE8FA);
	else if (percent < 0.8)
		return (0xFF91BF);
	else
		return (0xF7638F);
}
