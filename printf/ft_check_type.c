/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:21:37 by brisly            #+#    #+#             */
/*   Updated: 2022/11/08 08:29:18 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_check_type(char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	if (c == 's')
		count +=
	if (c == 'p')
	if (c == 'd' || 'i')

	if (c == 'u')

	if (c == 'x')

	if (c == 'X')

	if (c == '%')
	
}

/*%c Affiche un seul caractère.
• %s Affiche une chaîne de caractères (telle que définie par la convention C).
• %p L’argument de pointeur void * doit être affiché en hexadécimal.
• %d Affiche un nombre décimal (base 10).
• %i Affiche un entier en base 10.
• %u Affiche un nombre décimal non signé (base 10).
• %x Affiche un nombre en hexadécimal (base 16) avec des lettres minuscules.
• %X Affiche un nombre en hexadécimal (base 16) avec des lettres majuscules.
• %% Affiche un signe pourcentage. */