/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:51:03 by lfabbian          #+#    #+#             */
/*   Updated: 2022/11/04 17:51:25 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printf(const char *print_details, ...)
{
    int     i;
    va_list args;

    va_start (args, print_details);
    va_end (args);
}

int main()
{
    printf("something random.\n");
}