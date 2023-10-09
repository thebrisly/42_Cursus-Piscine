/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:26:29 by lfabbian          #+#    #+#             */
/*   Updated: 2023/10/09 13:42:28 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// In this exercise we will use a container that uses key/value : STD::MAP !

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cerr << "Error: No file name provided." << std::endl;

    else 
    {
        std::string given_file = argv[1];

        BitcoinExchange bitcoin_exchange("data.csv");
        bitcoin_exchange.display_change(given_file);
    }

}

