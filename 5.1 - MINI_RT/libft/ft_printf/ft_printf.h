/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:12:03 by fgrasset          #+#    #+#             */
/*   Updated: 2023/02/10 14:00:17 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft.h"

int	ft_printf(const char *string, ...);
int	printf_c(char c);
int	printf_s(char *s);
int	printf_d(int n);
int	printf_u(unsigned int n);
int	printf_x(unsigned int n);
int	printf_xx(unsigned int n);
int	printf_p(unsigned long cpy);

#endif
