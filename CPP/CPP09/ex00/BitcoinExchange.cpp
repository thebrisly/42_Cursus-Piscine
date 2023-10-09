/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:46:47 by lfabbian          #+#    #+#             */
/*   Updated: 2023/10/09 10:23:39 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& filename)
{
    std::cout << "\033[90mConstructor for BitcoinExchange called\033[0m" << std::endl;

    std::ifstream db_file(filename.c_str());
    std::string line;

    if (!db_file.is_open()) {
        std::cerr << "Error: Could not open file '" << filename << "'." << std::endl;
        return ;
    }

    while (std::getline(db_file, line)) 
    {
        size_t sep = line.find(',');
        if (sep != std::string::npos) 
        {
            std::string key = line.substr(0, sep);
            float value = std::atof(line.substr(sep + 1).c_str());
            _database[key] = value;
        }
    }
    
    db_file.close();
}


BitcoinExchange::~BitcoinExchange() {
    std::cout << "\033[90mDestructor for BitcoinExchange called\033[0m" << std::endl;
}


BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) {
    std::cout << "\033[90mCopy constructor for BitcoinExchange called\033[0m" << std::endl;
    *this = src;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src) {
    (void) src;
    std::cout << "\033[90mAssignement operator for BitcoinExchange called\033[0m" << std::endl;
    return *this;

}