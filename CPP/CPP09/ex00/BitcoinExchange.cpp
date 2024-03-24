/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 07:38:45 by laura             #+#    #+#             */
/*   Updated: 2024/03/24 08:59:17 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


/******************************************/
/* ---- CONSTRUCTORS & DESTRUCTORS ------ */
/******************************************/

BitcoinExchange::BitcoinExchange(void){
    std::cout << "\033[90mConstructor for BitcoinExchange\033[0m" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string fileName)
{
    std::cout << "\033[90mConstructor for BitcoinExchange\033[0m" << std::endl;

	std::ifstream file(fileName);
	if (!file.good())
		std::cerr << "\033[1;31mError:\033[0m invalid csv file" << std::endl;
	
	std::string line;
	
	while (getline(file, line))
	{
		std::string date = line.substr(0, line.find(','));  // line splitted into date
		std::string value = line.substr(line.find(',') + 1); //line splitted into amount
		if (date == "date")
			continue;
		if (!checkDate(date, 0) || !isNumeric(value, 0))
		{
			file.close();
			_data.clear();
			std::cout << "\033[1;31mError:\033[0m bad csv file" << std::endl;
			exit(0);
		}
		double amount = std::atof(value.c_str());
		
		_data[date] = amount;
	}
	if (_data.size() == 0)
	{
		file.close();
		_data.clear();
		std::cout << "\033[1;31mError:\033[0m empty csv file" << std::endl;
		exit(0);
	}
	file.close();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
    std::cout << "\033[90mCopy constructor for BitcoinExchange\033[0m" << std::endl;
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
    std::cout << "\033[90mAssignment operator for BitcoinExchange\033[0m" << std::endl;
	if (this != &src)
		_data = src.getData();
	return *this;
}

BitcoinExchange::~BitcoinExchange(void){
    std::cout << "\033[90mDestructor for BitcoinExchange\033[0m" << std::endl;
    _data.clear();
}

/******************************************/
/* ----------- GETTERS/SETTERS ---------- */
/******************************************/

std::map<std::string, double> BitcoinExchange::getData() const {
	return _data;
}

/******************************************/
/* ------- BTC_EXCHANGE Functions ------- */
/******************************************/

double BitcoinExchange::exchange(std::string date, double value) const
{
	std::string index;

	index = findRightDate(date);
	return this->_data.find(index)->second * value;
}

int BitcoinExchange::checkDate(std::string date, int mode) const
{
	std::istringstream iss(date);
	std::string year, month, day;
	double num;
	
	if (mode == 1 && date < this->_data.begin()->first)
		return 0;

	std::getline(iss, year, '-');
	if (year.length() != 4  || !isNumeric(year, 1))
		return 0;

	num = atof(year.c_str());
	if (num < 2009) //did that because the bitcoin didn't exist before.
		return 0;

	std::getline(iss, month, '-');
	if (month.length() != 2  || !isNumeric(month, 1))
		return 0;

	num = atof(month.c_str());
	if (num < 1 || num > 12)
		return 0;

	std::getline(iss, day, ' ');
	if (day.length() != 2  || !isNumeric(day, 1))
		return 0;	
    
	num = atof(day.c_str());
	if (num < 1 || num > 31)
		return 0;

	return 1;
}

std::string BitcoinExchange::findRightDate(const std::string &date) const
{
	std::map<std::string, double>::const_iterator begin = this->_data.begin();
	std::map<std::string, double>::const_iterator end = this->_data.end();
	std::string result = begin->first;
	
	while (begin != end)
	{
		if (begin->first > date)
			return result;
		result = begin->first;
		begin++;
	}
	return result;
}

bool BitcoinExchange::isNumeric(const std::string& str, int mode) const
{
	int count = 0;
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
		if (mode == 0)
		{
			if ( *it == '.')
				count++;
			if ((!isdigit(*it) && *it != '.') || count > 1)
				return false;
		}
		if (mode == 1 && !isdigit(*it))
			return false;
	}
	return true;
}

int BitcoinExchange::checkNumber(double number) const
{
	if (number < 0) {
		std::cerr << "\033[1;31mError:\033[0m not a positive number." << std::endl;
		return 0;
	}
	else if (number > 2147483647) {
		std::cerr << "\033[1;31mError:\033[0m too large a number." << std::endl;
		return 0;
	}
	return 1;
}

void BitcoinExchange::printData() const
{
	for (std::map<std::string, double>::const_iterator it = _data.begin(); it != _data.end(); ++it)
		std::cout << it->first << ": " << it->second << "\n";
}