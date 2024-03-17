#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <map>
#include <filesystem>

class BitcoinExchange
{
	public :
		BitcoinExchange();
		BitcoinExchange(const std::string datas_file);
		BitcoinExchange(const BitcoinExchange & src);
		BitcoinExchange & operator=(const BitcoinExchange & rhs);

		std::multimap<std::string, float> get_mp_data() const;
		std::multimap<int, std::string> get_output() const;
		void calculate(const std::string input_file);
		void display();

		class IssueWithDatas : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "Error : incorrect CSV file.";
			}
		};

	class DisplayMultimap
	{
		public:
			template <typename T>
			void operator()(T & a)
			{
				std::cout << a.first << " => " << a.second << std::endl;
			}
	};

	private :
    	std::multimap<std::string, float> _mp_data;
    	std::multimap<int, std::string> _output;

		std::string extract_date (std::string line);
		std::string extract_value (std::string line);
		bool date_format_is_valid(std::string date);
		bool value_format_is_valid (std::string value);

		float calculate_bc_value(const std::string input_date, const float input_value);

};

#endif