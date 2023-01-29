/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:08:47 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/29 13:57:44 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_init *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < s->int_a - 1)
	{
		while (s->pile_a[i] < s->pile_a[i + 1])
		{
			count++;
			i++;
		}
		i++;
	}
	if (count == s->int_a - 1)
		return (1);
	else
		return (0);
}

void	check_max_min(char *str)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		if (str[0] == '-')
		{
			if (len > 11)
				error("Error");
			if (len == 11 && ft_strncmp("-2147483648", str, 11) < 0)
				error("Error");
		}
		else
		{
			if (len > 10)
				error("Error");
			if (len == 10 && ft_strncmp("2147483647", str, 10) < 0)
				error("Error");
		}
	i++;
	}
}

void	check_non_num(t_init *ps, char c)
{
	if ((c == '-' || c == '+'))
		ps->j++;
	else if (ft_isdigit(c) == 0)
		error("Error");
	ps->j++;
}

void	check_doubles(int *tab, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (tab[i] == tab[j])
				error("Error");
			j++;
		}
		i++;
	}
}
