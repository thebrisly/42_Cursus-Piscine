#include "BitcoinExchange.hpp"
#include <typeinfo>

BitcoinExchange::BitcoinExchange(){};

BitcoinExchange::BitcoinExchange (const std::string datas_file)
{
	std::ifstream file;
	file.open(datas_file);

	if(!file)
	{
		throw IssueWithDatas();
	}
	else
	{
		file.close();
	}

    std::ifstream csv_file(datas_file);
    std::istream_iterator<std::string> it_csv(csv_file);
    std::istream_iterator<std::string> it_csv_end;

	++it_csv;
	while (it_csv != it_csv_end)
	{	
		//std::cout << *it_csv << std::endl;
		int ind_coma = (*it_csv).find(',');
		if (ind_coma == -1)
		{
			std::cout << "Line : " << (*it_csv) << std::endl;
			throw IssueWithDatas();
		}
		std::string date = (*it_csv).substr(0, ind_coma);
		if (this->date_format_is_valid(date) == false)
		{
			std::cout << "Line : " << (*it_csv) <<std::endl;
			throw IssueWithDatas();
		}

		std::string exchange_rate_str = (*it_csv).substr(ind_coma + 1, (*it_csv).size());
		//std::cout << "("<< exchange_rate_str <<")" <<std::endl;
		if (this->value_format_is_valid(exchange_rate_str) == false)
		{
			std::cout << "Line : " << (*it_csv) <<std::endl;
			throw IssueWithDatas();
		}

		float exchange_rate = atof(exchange_rate_str.c_str());
		if (exchange_rate < 0)
		{
			std::cout << "Line : " << (*it_csv) <<std::endl;
			throw IssueWithDatas();
		}
		this->_mp_data.insert(std::make_pair(date, exchange_rate));	
		++it_csv;
	}
	//for_each(this->_mp_data.begin(), this->_mp_data.end(), DisplayMultimap());
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange & src)
{
	this->_mp_data = src.get_mp_data();
	this->_output = src.get_output();
};

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & rhs)
{
	if (this != &rhs)
	{
		this->_mp_data = rhs.get_mp_data();
		this->_output = rhs.get_output();
	}
	return *this;
}

std::multimap<std::string, float> BitcoinExchange::get_mp_data() const
{
	return this->_mp_data;
}

std::multimap<int, std::string> BitcoinExchange::get_output() const
{
	return this->_output;
}

void BitcoinExchange::calculate(const std::string input_file)
{
	std::ifstream input(input_file);
	std::string line;
	std::getline(input, line);

	int line_count;

	line_count = 0;
	while (std::getline(input, line))
	{
		if (line.find(" | ") == std::string::npos || this->date_format_is_valid(this->extract_date(line)) == false || this->value_format_is_valid(this->extract_value(line)) == false)
		{
			this->_output.insert(std::make_pair(line_count, ("Error: bad input => " + line)));
		}
		else
		{
			float value = atof(this->extract_value(line).c_str());
			std::string date = this->extract_date(line);
			if (value < 0)
			{
				this->_output.insert(std::make_pair(line_count, "Error: not a positive number."));

			}
			else if (value > 1000)
			{
				this->_output.insert(std::make_pair(line_count, "Error: too large number."));
			}
			else
			{
				std::ostringstream oss;
				oss << date << " => " << value << " = " << calculate_bc_value(date, value);
				this->_output.insert(std::make_pair(line_count, oss.str()));
			}
		}
		line_count++;
	}
};

void BitcoinExchange::display()
{
	for (std::multimap<int, std::string>::iterator it = this->_output.begin(); it != this->_output.end(); ++it)
	{
		std::cout << (*it).second << std::endl;
	}

}

std::string BitcoinExchange::extract_date (std::string line)
{
	int indexVL = line.find(" | ");
	return line.substr(0, indexVL);
}

std::string BitcoinExchange::extract_value (std::string line)
{
	int indexVL = line.find(" | ");
	return line.substr(indexVL + 3, line.size());
}

bool BitcoinExchange::date_format_is_valid(std::string date)
{
	std::istringstream str_f(date);
	int n = 0;
	char c = 0;

	str_f >> n >> c;
	//std::cout << "n = " << n << " c = " << c << std::endl;
	if ((n < 1900 || n > 9999) || (c != '-'))
	{
		//std::cout << "VERIF3";

		return false;
	}
	
	n = 0;
	c = 0;
	str_f >> n >> c;
	//std::cout << "n = " << n << " c = " << c << std::endl;
	if ((n < 1 || n > 12) || (c != '-'))
	{
		//std::cout << "VERIF2";

		return false;
	}

	n = 0;
	c = 0;
	str_f >> n;
	//std::cout << "n = " << n << std::endl;
	if ((n < 1 || n > 31))
	{
		//std::cout << "VERIF";
		return false;
	}	

	return true;
}

bool BitcoinExchange::value_format_is_valid (std::string value)
{

	if (value.size() == 0)
	{
		return false;
	}

	std::istringstream str_f(value);
	char c;
	
	str_f >> c;
	if (c == '-')
	{
		str_f >> c;
	}

	while (str_f)
	{
		if ((c < '0' || c > '9') && c != '.')
		{
			return false;
		}
		str_f >> c;
	}
	return true;
}

float BitcoinExchange::calculate_bc_value (const std::string input_date, const float input_value)
{
	std::multimap<std::string,float>::iterator it_data = this->_mp_data.begin();
	std::multimap<std::string,float>::iterator it_data_end = this->_mp_data.end();

	if (it_data == it_data_end)
	{
		return 0.0;
	}


	while (it_data != it_data_end && input_date >= it_data->first)
		++it_data;

	if (it_data == this->_mp_data.begin())
		return input_value * it_data->second;
	
	it_data--;
	return input_value * it_data->second;
}
