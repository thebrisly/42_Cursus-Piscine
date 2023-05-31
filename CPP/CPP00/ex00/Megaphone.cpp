/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:40:34 by brisly            #+#    #+#             */
/*   Updated: 2023/05/31 13:48:14 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    (void) argc;
    int words = 1;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        while (words < argc)
        {
            int i = 0;
            while (argv[words][i])
            {
                std::cout << (char) std::toupper(argv[words][i]);
                i++;
            }
            words++;
        }
    }
    std::cout << std::endl;
}