/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 10:31:01 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/24 14:08:45 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_init	ps;

	ps.counter = 0;
	(void) argv;
	if (argc > 1)
	{
		if (argc == 2)
			two_args_init(&ps, argc, argv);
		else
			mult_args_init(&ps, argc, argv);
		int i = 0;
		ft_printf("\nAVANT PUSH SWAP: \nPILE A | PILE B\n");
		while (i < ps.int_numb)
		{
			ft_printf("%d | %d\n", ps.pile_a[i], ps.pile_b[i]);
			i++;
		}
		algorithms(&ps);
		i = 0;
		ft_printf("\nAPRES PUSH SWAP: \nPILE A | PILE B\n");
		while (i < ps.int_numb)
		{
			ft_printf("%d | %d\n", ps.pile_a[i], ps.pile_b[i]);
			i++;
		}
	}
}

void	two_args_init(t_init *ps, int argc, char **argv)
{
	(void) argc;
	(void) argv;
	(void) ps;
}

void	mult_args_init(t_init *ps, int argc, char **argv)
{
	int	i;

	i = -1;
	ps->int_numb = argc - 1;
	ps->pile_a = malloc(ps->int_numb * sizeof(int));
	if (!ps->pile_a)
		error("Malloc Error\n");
	ps->pile_b = malloc(ps->int_numb * sizeof(int));
	if (!ps->pile_b)
		error("Malloc Error\n");
	while (++i < ps->int_numb)
		ps->pile_a[i] = ft_atoi(argv[i + 1]);
}
