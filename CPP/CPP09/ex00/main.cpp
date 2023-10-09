/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:26:29 by lfabbian          #+#    #+#             */
/*   Updated: 2023/10/09 10:25:56 by lfabbian         ###   ########.fr       */
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
        std::string filename = argv[1];
        std::ifstream input_file(filename.c_str());

        if (!input_file.is_open())
        {
            std::cerr << "Error: Could not open file '" << filename << "'." << std::endl;
            return 1;
        }

        BitcoinExchange bitcoin_exchange("data.csv");


    }
}
