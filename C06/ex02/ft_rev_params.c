/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:47:26 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/10 10:18:04 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		write(1, &c[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	while (argc > 1)
	{
		ft_putchar(argv[argc - 1]);
		argc--;
	}
}
