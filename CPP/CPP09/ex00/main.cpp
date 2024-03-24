/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 19:41:31 by laura             #+#    #+#             */
/*   Updated: 2024/03/24 08:59:21 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        std::cerr << "\033[1;31mError: Missing input file argument OR too many inputs.\033[0m" << std::endl;
        std::cerr << "\033[1;31mFormat is : ./btc [.txt file]\033[0m" << std::endl;
    }
    else 
    {   
        std::ifstream infile(argv[1]);
        if (!infile.is_open()) 
        {
            std::cerr << "Error: could not open file." << std::endl;
        }
        
        else
        {
            BitcoinExchange btc_exchange("data.csv");           
            std::string line;
            
            while (std::getline(infile, line))
            {
                int count = 0;
                size_t i = 0;
                while (i < line.size()) {
                    if (line[i] == '|')
                        count++;
                    i++;
                }

                if (line.empty()) {
                    std::cerr << "\033[1;1mWarning:\033[0m empty line - please use this format : date | value " << line << std::endl;
                    continue;
                }

                if (count != 1) {
                    std::cerr << "\033[1;31mError:\033[0m bad input => " << line << std::endl;
                    continue;
                }

                std::istringstream iss(line);
                std::string date, value;

                std::getline(iss, date, '|');
                if (date == "date ")
                    continue;
                if (!btc_exchange.checkDate(date, 1))
                {
                    std::cerr << "\033[1;31mError:\033[0m bad input => " << line << std::endl;
                    continue;
                }
                
                std::getline(iss, value, '|');
                if (value.empty())
                {
                    std::cerr << "\033[1;31mError:\033[0m bad input => " << date << std::endl;
                    continue;
                }
                double number = std::atof(value.c_str());
                if (!btc_exchange.checkNumber(number))
                    continue;
                
                std::cout << date << "=> " << number << " = " << btc_exchange.exchange(date, number) << std::endl;
            }
        }
    }
}