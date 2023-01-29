/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:11:52 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/29 14:31:05 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf.h"
# include "libft.h"
# include <stdlib.h>

typedef struct s_init {
	char	**arguments;
	int		*pile_a;
	int		*pile_b;
	int		int_a;
	int		int_b;
	int		min;
	int		i;
	int		j;
	int		counter;
	int		counter_a;
}	t_init;

/* main.c*/
void	mult_args_init(t_init *ps, int argc, char **argv);
void	two_args_init(t_init *ps, char **argv);

/* errors.c */
int		error(char *error_message);

/* instructions1/2/3.c */
void	ft_swapa(t_init *s);
void	ft_swapb(t_init *s);
void	ft_swaps(t_init	*s);
void	ft_pusha(t_init *s);
void	ft_pushb(t_init *s);
void	ft_rotatea(t_init *s);
void	ft_rotateb(t_init *s);
void	ft_rotater(t_init *s);
void	ft_reverse_rotatea(t_init *s);
void	ft_reverse_rotateb(t_init *s);
void	ft_reverse_rotater(t_init *s);

/* algorithms1/2.c */
void	algorithms(t_init *s);
void	big_algorithm(t_init *s);
void	two_args_alg(t_init *s);
void	three_int_alg(t_init *s);
void	four_int_alg(t_init *s);
void	five_int_alg(t_init *s);

/* alg_utils.c */
void	find_smallest(t_init *s);

/* checks.c */
int		check_order(t_init *s);
void	check_non_num(t_init *ps, char c);
void	check_max_min(char *str);
void	check_doubles(int *tab, int len);

/* free.c */
void	free_stacks(t_init *s);

/* helpers.c */
void	three_alg_help(t_init *s);
void	create_stacks(t_init *s);
long	ft_atol(const char *str);

#endif
