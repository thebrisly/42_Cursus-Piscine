/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:16:55 by lfabbian          #+#    #+#             */
/*   Updated: 2022/12/14 13:26:09 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    int len;

    len = 0;
    if (argc == 2)
    {
        while (argv[1][len])
            len++;
        len--;
        while (len >= 0)
        {
            write (1, &argv[1][len], 1);
            len--;
        }
    }
    write (1, "\n", 1);
}
