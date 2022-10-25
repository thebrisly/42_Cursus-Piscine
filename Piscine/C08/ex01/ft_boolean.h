/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:57:11 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/20 19:52:19 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H
# define EVEN(nbr) nbr = (nbr % 2) == 0 ? 1 : 0
# define SUCCESS 0
# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"
# include <unistd.h>

enum e_bool
{
	FALSE,
	TRUE
};

typedef enum e_bool	t_bool;

void	ft_putstr(char *str);
t_bool	ft_is_even(int nbr);

#endif
