/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuriens <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:01:59 by rjuriens          #+#    #+#             */
/*   Updated: 2022/09/18 15:33:06 by rjuriens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush.h"

void	ft_trim_last_space(char *str)
{
	if (str[ft_strlen(str) - 1] == ' ')
		str[ft_strlen(str) - 1] = '\0';
}

void	ft_catnb(int len, t_number *tab, unsigned long long int *nb, char **t)
{
	int						in;
	unsigned long long int	n;

	in = find_index(ft_itoa(ft_pow(1000, len)), tab, count_lines(t[1]));
	n = (*nb - *nb % ft_pow(1000, len)) / ft_pow(1000, len);
	t[0] = ft_strcat(t[0], ft_split_hundreds(n, tab, t[1]));
	if (len != 0 && (*nb - *nb % ft_pow(1000, len)) / ft_pow(1000, len) > 0)
	{
		t[0] = ft_strcat (t[0], tab[in].letter_num);
		t[0] = ft_strcat(t[0], " ");
	}
	*nb %= ft_pow(1000, len);
}

char	*ft_split_number(char *c_nb, t_number *tab, char *file)
{
	char					*str;
	unsigned long long int	nb;
	int						len;
	int						in;
	char					*tabc[2];

	len = (ft_strlen(c_nb) / 3);
	nb = ft_atoi(c_nb);
	str = malloc(sizeof(char) * 100);
	tabc[0] = str;
	tabc[1] = file;
	if (nb == 0)
	{
		in = find_index("0", tab, count_lines(file));
		return (ft_strcat(str, tab[in].letter_num));
	}
	while (len >= 0)
	{
		ft_catnb(len, tab, &nb, tabc);
		len -= 1;
	}
	ft_trim_last_space(str);
	return (str);
}
