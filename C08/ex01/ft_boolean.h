/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:57:11 by lfabbian          #+#    #+#             */
/*   Updated: 2022/09/19 19:04:51 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H
# define EVEN(nbr) nbr = (nbr % 2) == 0 ? 1 : 0
# define SUCCESS 0

enum e_bool
{
	FALSE,
	TRUE
};

typedef enum e_bool t_bool;

# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"

#endif
