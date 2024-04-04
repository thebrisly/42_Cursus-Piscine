/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:46:14 by lfabbian          #+#    #+#             */
/*   Updated: 2022/12/18 15:40:44 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	scan(char *str, char c, int nb)
{
	while (nb >= 0)
	{
		if (str[nb] == c)
			return (0);
		nb--;
	}
	return (1);
}

void	inter(char *str1, char *str2)
{
	int i = 0;
	int	j;

	while(str1[i])
	{
		j = 0;
		while(str2[j])
		{
			if (str1[i] == str2[j])
			{
				if (scan(str1, str1[i], i - 1))
					write(1, &str1[i], 1);
				break;
			}
			j++;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
