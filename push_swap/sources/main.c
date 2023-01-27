/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 10:31:01 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/27 15:54:37 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_init	ps;

	ps.counter = 0;
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
		check_max_min(ps.pile_a, ps.int_a);
		if (in_order(&ps))
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
		while (ps->arguments[ps->int_a][ps->j])
		{
			check_non_num(ps->arguments[ps->int_a][ps->j]);
			ps->j++;
		}
		ps->int_a++;
	}
	create_stacks(ps);
	while (ps->arguments[ps->i])
	{
		ps->pile_a[ps->i] = ft_atol(ps->arguments[ps->i]);
		free(ps->arguments[ps->i]);
		ps->i++;
	}
	free(ps->arguments);
}

void	mult_args_init(t_init *ps, int argc, char **argv)
{
	int	i;

	i = 0;
	ps->tab = malloc(sizeof(char) * argc - 1);
	if (!ps->tab)
		error("Error [MALLOC]");
	while (i < argc - 1)
	{
		ps->tab[i] = *argv[i + 1];
		i++;
	}
	i = 0;
	while (ps->tab[i])
	{
		ft_printf("[%d] = %s\n", i, ps->tab[i]);
		i++;
	}
}

/*void	mult_args_init(t_init *ps, int argc, char **argv)
{
	int	i;

	i = -1;
	ps->int_a = argc - 1;
	ps->int_b = 0;
	ps->pile_a = malloc(ps->int_a * sizeof(int));
	if (!ps->pile_a)
		error("Error [Malloc]\n");
	ps->pile_b = malloc(ps->int_b * sizeof(int));
	if (!ps->pile_b)
		error("Error [Malloc]\n");
	while (++i < ps->int_a)
		ps->pile_a[i] = ft_atoi(argv[i + 1]);
}*/

/*int	main(int argc, char **argv)
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
		int	i = 0;
		ft_printf("\nAVANT PUSH SWAP: \nPILE A | PILE B\n");
		while (i < ps.int_a)
		{
			ft_printf("%d | %d\n", ps.pile_a[i], ps.pile_b[i]);
			i++;
		}
		//errors
		if (in_order(&ps))
			free_stacks(&ps);
		else
			algorithms(&ps);
		//enlever tou ce qu'il y a en bas et mettre free a la fin de l'algorithme ou a la fin ici
		i = 0;
		ft_printf("\nAPRES PUSH SWAP: \nPILE A | PILE B\n");
		while (i < (argc - 1))
		{
			ft_printf("%d | %d\n", ps.pile_a[i], ps.pile_b[i]);
			i++;
		}
		free(ps.pile_a);
	}
}
*/
