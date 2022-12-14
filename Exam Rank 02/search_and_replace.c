/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:14:39 by lfabbian          #+#    #+#             */
/*   Updated: 2022/12/14 14:30:05 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc == 4)
    {
        while (argv[1][i])
        {
            if (argv[1][i] == *argv[2])
                argv[1][i] = *argv[3];
            write (1, &argv[1][i], 1);
            i++;
        }
    }
    write (1, "\n", 1);
}