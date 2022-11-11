/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:52:42 by lfabbian          #+#    #+#             */
/*   Updated: 2022/11/11 15:58:51 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *format, ...);
int	ft_check_type(const char type, va_list args);
int	ft_put_c(char c);
int	ft_put_s(char *str);
int	ft_put_d_i(int nb);
int	ft_put_u(unsigned int nb);
int	ft_put_x(unsigned int nb, int type);
int	ft_put_p(intptr_t *arg);
int	ft_base16(unsigned int nb, char *alpha);

#endif