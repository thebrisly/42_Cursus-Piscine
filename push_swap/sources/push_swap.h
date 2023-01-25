/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:11:52 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/25 16:01:51 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf.h"
# include "libft.h"
# include <stdlib.h>

typedef struct s_init {
	int	*pile_a;
	int	*pile_b;
	int	int_a;
	int	int_b;
	int	counter;
}	t_init;


/* main.c*/
void	mult_args_init(t_init *ps, int argc, char **argv);
void	two_args_init(t_init *ps, int argc, char **argv);
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

/* checks.c */
int		in_order(t_init *s);
void	free_stacks(t_init *s);

/* no p_place.c */
void	three_alg_help(t_init *s);

#endif
