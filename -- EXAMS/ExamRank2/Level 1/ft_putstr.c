/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:26:30 by lfabbian          #+#    #+#             */
/*   Updated: 2023/02/19 22:00:51 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
        write(1, &str[i++], 1);
}


void	ft_putstr(char *str)
{
	
}


/*int main()
{
    char    *hello;

    hello = "hello";
    ft_putstr(hello);
}*/