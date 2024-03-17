#include "BitcoinExchange.hpp"

int main(int argc, char* argv[])
{

	if (argc != 2)
	{
		std::cerr << "Error: could not open file." <<std::endl;
		return 0;
	}

	std::ifstream file;
	file.open(argv[1]);

	if(!file)
	{
		std::cerr << "Error: could not open file : " << argv[1] <<std::endl;
		return 0;
	}
	else
	{
		file.close();
	}

	try
	{
		BitcoinExchange bitcoin_exchange("data.csv");
		bitcoin_exchange.calculate(argv[1]);
		bitcoin_exchange.display();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;


	// std::cout << "\033[1;34m" << "TEST 1 : BitcoinExchange() :" << "\033[0m" << std::endl;
	// try
	// {
	// 	BitcoinExchange bitcoin_exchange;
	// 	bitcoin_exchange.calculate(argv[1]);
	// 	bitcoin_exchange.display();
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// std::cout << std::endl;

	// std::cout << "\033[1;34m" << "TEST 2 : BitcoinExchange(const BitcoinExchange & src) :" << "\033[0m" << std::endl;
	// try
	// {
	// 	BitcoinExchange bitcoin_exchange0("data.csv");
	// 	bitcoin_exchange0.calculate(argv[1]);
	// 	BitcoinExchange bitcoin_exchange1(bitcoin_exchange0);
	// 	bitcoin_exchange1.display();
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// std::cout << std::endl;

	// std::cout << "\033[1;34m" << "TEST 3 : BitcoinExchange & operator=(const BitcoinExchange & rhs) :" << "\033[0m" << std::endl;
	// try
	// {
	// 	BitcoinExchange bitcoin_exchange0;
	// 	BitcoinExchange bitcoin_exchange1("data.csv");
	// 	bitcoin_exchange1.calculate(argv[1]);

	// 	bitcoin_exchange0 = bitcoin_exchange1;

	// 	bitcoin_exchange0.display();
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// std::cout << std::endl;

	// std::cout << "\033[1;34m" << "TEST 4 : test with a corrupted database :" << "\033[0m" << std::endl;
	// std::cout << "\033[1;36m" << "TEST 4.1 :" << "\033[0m" << std::endl;
	// try
	// {
	// 	BitcoinExchange bitcoin_exchange0;
	// 	BitcoinExchange bitcoin_exchange1("data_with_errors/existepas.csv");
	// 	bitcoin_exchange1.calculate(argv[1]);

	// 	bitcoin_exchange0 = bitcoin_exchange1;

	// 	bitcoin_exchange0.display();
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// std::cout << std::endl;

	// std::cout << "\033[1;36m" << "TEST 4.2 :" << "\033[0m" << std::endl;
	// try
	// {
	// 	BitcoinExchange bitcoin_exchange0;
	// 	BitcoinExchange bitcoin_exchange1("data_with_errors/data_with_errors1.csv");
	// 	bitcoin_exchange1.calculate(argv[1]);

	// 	bitcoin_exchange0 = bitcoin_exchange1;

	// 	bitcoin_exchange0.display();
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// std::cout << std::endl;


	// std::cout << "\033[1;36m" << "TEST 4.3 :" << "\033[0m" << std::endl;
	// try
	// {
	// 	BitcoinExchange bitcoin_exchange0;
	// 	BitcoinExchange bitcoin_exchange1("data_with_errors/data_with_errors2.csv");
	// 	bitcoin_exchange1.calculate(argv[1]);

	// 	bitcoin_exchange0 = bitcoin_exchange1;

	// 	bitcoin_exchange0.display();
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// std::cout << std::endl;

	// std::cout << "\033[1;36m" << "TEST 4.4 :" << "\033[0m" << std::endl;
	// try
	// {
	// 	BitcoinExchange bitcoin_exchange0;
	// 	BitcoinExchange bitcoin_exchange1("data_with_errors/data_with_errors3.csv");
	// 	bitcoin_exchange1.calculate(argv[1]);

	// 	bitcoin_exchange0 = bitcoin_exchange1;

	// 	bitcoin_exchange0.display();
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// std::cout << std::endl;

	// std::cout << "\033[1;36m" << "TEST 4.5 :" << "\033[0m" << std::endl;
	// try
	// {
	// 	BitcoinExchange bitcoin_exchange0;
	// 	BitcoinExchange bitcoin_exchange1("data_with_errors/data_with_errors4.csv");
	// 	bitcoin_exchange1.calculate(argv[1]);

	// 	bitcoin_exchange0 = bitcoin_exchange1;

	// 	bitcoin_exchange0.display();
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// std::cout << std::endl;

	// std::cout << "\033[1;36m" << "TEST 4.6 :" << "\033[0m" << std::endl;
	// try
	// {
	// 	BitcoinExchange bitcoin_exchange0;
	// 	BitcoinExchange bitcoin_exchange1("data_with_errors/data_with_errors5.csv");
	// 	bitcoin_exchange1.calculate(argv[1]);

	// 	bitcoin_exchange0 = bitcoin_exchange1;

	// 	bitcoin_exchange0.display();
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// std::cout << std::endl;

	// std::cout << "\033[1;36m" << "TEST 4.7 :" << "\033[0m" << std::endl;
	// try
	// {
	// 	BitcoinExchange bitcoin_exchange0;
	// 	BitcoinExchange bitcoin_exchange1("data_with_errors/data_with_errors6.csv");
	// 	bitcoin_exchange1.calculate(argv[1]);

	// 	bitcoin_exchange0 = bitcoin_exchange1;

	// 	bitcoin_exchange0.display();
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// std::cout << std::endl;

	// std::cout << "\033[1;36m" << "TEST 4.8 :" << "\033[0m" << std::endl;
	// try
	// {
	// 	BitcoinExchange bitcoin_exchange0;
	// 	BitcoinExchange bitcoin_exchange1("data_with_errors/data_with_errors7.csv");
	// 	bitcoin_exchange1.calculate(argv[1]);

	// 	bitcoin_exchange0 = bitcoin_exchange1;

	// 	bitcoin_exchange0.display();
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// std::cout << std::endl;

	// std::cout << "\033[1;36m" << "TEST 4.9 :" << "\033[0m" << std::endl;
	// try
	// {
	// 	BitcoinExchange bitcoin_exchange0;
	// 	BitcoinExchange bitcoin_exchange1("data_with_errors/data_with_errors8.csv");
	// 	bitcoin_exchange1.calculate(argv[1]);

	// 	bitcoin_exchange0 = bitcoin_exchange1;

	// 	bitcoin_exchange0.display();
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// std::cout << std::endl;

	// std::cout << "\033[1;36m" << "TEST 4.10 :" << "\033[0m" << std::endl;
	// try
	// {
	// 	BitcoinExchange bitcoin_exchange0;
	// 	BitcoinExchange bitcoin_exchange1("data_with_errors/data_with_errors9.csv");
	// 	bitcoin_exchange1.calculate(argv[1]);

	// 	bitcoin_exchange0 = bitcoin_exchange1;

	// 	bitcoin_exchange0.display();
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// std::cout << std::endl;

    return 0;
}
