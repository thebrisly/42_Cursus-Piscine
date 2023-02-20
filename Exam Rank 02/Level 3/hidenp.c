/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:41:25 by brisly            #+#    #+#             */
/*   Updated: 2023/02/20 11:54:37 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *to_find)
{
	int i = 0;
	while (to_find[i])
		i++;
	return(i);
}

int main(int argc, char **argv)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	len = ft_strlen(argv[1]);
	if (argc == 3)
	{
		while(argv[2][i])
		{
			if (argv[2][i] == argv[1][j])
				j++;
			i++;
		}
		if (j == len)
			write (1, "1", 1);
		else
			write (1, "0", 1);
	}
	write(1, "\n", 1);
}