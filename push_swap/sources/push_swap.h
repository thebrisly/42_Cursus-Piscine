/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:11:52 by lfabbian          #+#    #+#             */
/*   Updated: 2023/02/18 11:25:40 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf.h"
# include "libft.h"
# include <stdlib.h>
# define DEF_COLOR "\033[0;39m"
# define RED "\033[0;91m"
# define LONG_V 9223372036854775808

typedef struct s_init {
	char	**arguments;
	int		*pile_a;
	int		*pile_b;
	int		*tmp;
	int		int_a;
	int		int_b;
	int		min;
	int		i;
	int		j;
	int		counter;
	int		small_i;
	int		big_i;
	float	median;
}	t_init;

/* main.c*/
void	mult_args_init(t_init *ps, int argc, char **argv);
void	two_args_init(t_init *ps, char **argv);

/* errors.c */
int		error(void);

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
void	push_up(t_init *s);

/* checks.c */
int		check_order(t_init *s);
void	check_non_num(char *str);
void	check_max_min(char *str);
void	check_doubles(int *tab, int len);

/* free.c */
void	free_stacks(t_init *s);

/* helpers.c */
void	three_alg_help(t_init *s);
void	create_stacks(t_init *s);
void	init_stack(t_init *s);

/* normalize */
void	ft_normalize(t_init *s);

#endif
