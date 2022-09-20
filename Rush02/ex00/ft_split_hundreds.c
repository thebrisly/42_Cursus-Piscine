/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_hundreds.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuriens <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:14:05 by rjuriens          #+#    #+#             */
/*   Updated: 2022/09/18 15:03:42 by rjuriens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush.h"

char	*ft_cat_tens(t_number *tab, int	*t, char *str, int l)
{
	if (t[1] < 20 && t[1] != 0)
	{
		str = ft_strcat(str, tab[find_index(ft_itoa(t[1]), tab, l)].letter_num);
		str = ft_strcat(str, " ");
	}
	else if (t[1] == 0 && t[2] == 0 && t[0] != 0)
		return (str);
	else if (t[1] % 10 == 0 && t[2] == 0)
	{
		str = ft_strcat(str, tab[find_index(ft_itoa(t[1]), tab, l)].letter_num);
		str = ft_strcat(str, " ");
	}
	else
	{
		str = ft_strcat(str, tab[find_index(ft_itoa(t[1]), tab, l)].letter_num);
		str = ft_strcat(str, " ");
		str = ft_strcat(str, tab[find_index(ft_itoa(t[2]), tab, l)].letter_num);
		str = ft_strcat(str, " ");
	}
	return (str);
}

char	*ft_cat_hundreds(t_number *tab, int c, char *str, int lines)
{
	int	in;

	if (c != 0)
	{
		in = find_index(ft_itoa(c), tab, lines);
		str = ft_strcat(str, tab[in].letter_num);
		str = ft_strcat(str, " ");
		in = find_index("100", tab, lines);
		str = ft_strcat(str, tab[in].letter_num);
		str = ft_strcat(str, " ");
	}
	return (str);
}

char	*ft_split_hundreds(int nb, t_number *tab, char *file)
{
	char	*str;
	int		tabi[3];

	str = malloc(sizeof(char) * 100);
	if (nb <= 0)
		return ("");
	tabi[0] = nb / 100;
	tabi[2] = nb % 10;
	if (nb % 100 <= 20)
	{
		tabi[1] = nb % 100;
		tabi[2] = 0;
	}
	else
		tabi[1] = nb % 100 - tabi[2];
	ft_cat_hundreds(tab, tabi[0], str, count_lines(file));
	ft_cat_tens(tab, tabi, str, count_lines(file));
	return (str);
}
