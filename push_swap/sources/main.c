/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 10:31:01 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/29 14:12:31 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_init	ps;

	ps.int_a = 0;
	ps.int_b = 0;
	ps.i = 0;
	(void) argv;
	if (argc > 1)
	{
		if (argc == 2)
			two_args_init(&ps, argv);
		else
			mult_args_init(&ps, argc, argv);
		int	i = 0;
		ft_printf("\nAVANT PUSH SWAP: \nPILE A | PILE B\n");
		while (i < ps.int_a)
		{
			ft_printf("%d | %d\n", ps.pile_a[i], ps.pile_b[i]);
			i++;
		}
		check_doubles(ps.pile_a, ps.int_a);
		ps.counter = 0;
		if (check_order(&ps))
			free_stacks(&ps);
		else
			algorithms(&ps);
		i = 0;
		ft_printf("\nAPRES PUSH SWAP: \nPILE A | PILE B\n");
		while (i < (ps.int_a))
		{
			ft_printf("%d | %d\n", ps.pile_a[i], ps.pile_b[i]);
			i++;
		}
		free_stacks(&ps);
	}
}

void	two_args_init(t_init *ps, char **argv)
{
	ps->arguments = ft_split(argv[1], ' ');
	if (!ps->arguments)
		error("Error [MALLOC]");
	while (ps->arguments[ps->int_a])
	{
		ps->j = 0;
		ps->counter = 0;
		while (ps->arguments[ps->int_a][ps->j])
			check_non_num(ps, ps->arguments[ps->int_a][ps->j]);
		ps->int_a++;
	}
	create_stacks(ps);
	while (ps->arguments[ps->i])
	{
		check_max_min(ps->arguments[ps->i]);
		ps->pile_a[ps->i] = ft_atoi(ps->arguments[ps->i]);
		free(ps->arguments[ps->i]);
		ps->i++;
	}
	free(ps->arguments);
}

void	mult_args_init(t_init *ps, int argc, char **argv)
{
	ps->int_a = argc - 1;
	create_stacks(ps);
	while (ps->i < ps->int_a)
	{
		ps->j = 0;
		while (argv[ps->i + 1][ps->j])
			check_non_num(ps, argv[ps->i + 1][ps->j]);
		check_max_min(argv[ps->i + 1]);
		ps->pile_a[ps->i] = ft_atoi(argv[ps->i + 1]);
		ps->i++;
	}
}
