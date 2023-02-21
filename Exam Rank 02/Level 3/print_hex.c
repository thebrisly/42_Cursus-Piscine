/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:37:21 by brisly            #+#    #+#             */
/*   Updated: 2023/02/21 08:40:58 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int ft_atoi(char *str)
{
    int atoi = 0;
    int i = 0;
    
    while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
        atoi = atoi * 10 + str[i] - '0';
        i++;
    }
    return (atoi);
}

void print_hex(int number)
{
    char *digits = "0123456789abcdef";
    
    if (number >= 16)
        print_hex(number / 16);
    number = digits[number % 16];
    write (1, &number, 1);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        print_hex(ft_atoi(argv[1]));
    }
    write(1,"\n",1);
}