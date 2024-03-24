/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 07:34:26 by laura             #+#    #+#             */
/*   Updated: 2024/03/24 08:36:48 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange
{
	public :

		BitcoinExchange(const std::string file);                    // default constructor
		BitcoinExchange(BitcoinExchange const &src);                // copy constructor
		~BitcoinExchange(void);                                     // default destructor
		BitcoinExchange	&operator=(BitcoinExchange const &src);     // overloading operator for =

        std::map<std::string, double> getData() const;

        bool isNumeric(const std::string& str, int mode) const;
        int checkNumber(double number) const;
		int checkDate(std::string date, int mode) const;
		double exchange(std::string date, double value) const;
		std::string findRightDate(const std::string &date) const;
        void printData() const;

	private :
		BitcoinExchange(void);
		std::map<std::string, double> _data;                         // the place where we are storing the .csv

};

#endif