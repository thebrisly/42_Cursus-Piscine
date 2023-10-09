/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:46:47 by lfabbian          #+#    #+#             */
/*   Updated: 2023/10/09 14:33:34 by lfabbian         ###   ########.fr       */
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

    std::getline(db_file, line);
    while (std::getline(db_file, line)) 
    {
        size_t sep = line.find(',');
        if (sep != std::string::npos) 
        {
            std::string key = line.substr(0, sep);
            float value = std::atof(line.substr(sep + 1).c_str());
            this->_database[key] = value;
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
    std::cout << "\033[90mAssignement operator for BitcoinExchange called\033[0m" << std::endl;
    if (this != &src)
		this->_database = src._database;
	return *this;

}

// METHODS //

int BitcoinExchange::check_values(float value)
{
    if (value < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return 1;
    }
    else if (value >= INT_MAX)
    {
        std::cerr << "Error: number too large." << std::endl;
        return 1;
    }
    else
        return 0;
}

int BitcoinExchange::check_keys(const std::string& key)
{
    (void) key;
    //transformer la key en date
    // si la date n'existe pas, afficher une erreur
    // si la date est inférieure à 2009-01-02, afficher une erreur (bitcoin n'existait pas)
    // si erreur retourne 1
    //sinon retourner 0
    return 0;
}

void BitcoinExchange::display_change(const std::string& filename)
{
    std::ifstream input_file(filename.c_str());
    std::string line;

    if (!input_file.is_open()) {
        std::cerr << "Error: Could not open file '" << filename << "'." << std::endl;
        return ;
    }

    std::getline(input_file, line);
    
    while (std::getline(input_file, line)) 
    {
        size_t sep = line.find('|');
        if (sep != std::string::npos) 
        {
            std::string key = line.substr(0, sep);
            float value = std::atof(line.substr(sep + 1).c_str());
            if (this->check_values(value) == 0 && this->check_keys(key) == 0)
            {
                std::cout << key << "=> " << value << "\033[90m($BTC)\033[0m = " << std::endl;
            }
            else
                continue ;

        }
    }
    
    input_file.close();
}