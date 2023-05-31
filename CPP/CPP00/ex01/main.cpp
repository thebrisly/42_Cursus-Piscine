/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:26:20 by brisly            #+#    #+#             */
/*   Updated: 2023/05/31 22:37:59 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        std::string entry(argv[1]);
    }
    else
        std::cout << "Only one action needed. ADD, SEARCH or EXIT.\n";
}