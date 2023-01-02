/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:52:42 by lfabbian          #+#    #+#             */
/*   Updated: 2022/11/12 10:48:02 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_check_type(const char type, va_list args);
int	ft_put_c(char c);
int	ft_put_s(char *str);
int	ft_put_d_i(int nb);
int	ft_put_u(unsigned int nb);
int	ft_put_x(unsigned int nb, int type);
int	ft_put_p(void *arg);
int	ft_base16(unsigned long nb, char *alpha);

#endif