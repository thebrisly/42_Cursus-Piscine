#include "RPN.hpp"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return 0;
	}

	std::cout << "Input : " << argv[1] << std::endl;

	RPN rpn(argv[1]);
	try
	{
		rpn.process();
		rpn.display();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	/*TEST*/
	// std::cout << std::endl;
	// std::cout << "\033[1;34m" << "TEST 1 : RPN() :" << "\033[0m" << std::endl;

	// RPN rpn_no_arg;
	// try
	// {
	// 	rpn_no_arg.process();
	// 	rpn_no_arg.display();
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// std::cout << std::endl;

	// std::cout << "\033[1;34m" << "TEST 2 : RPN(const RPN &src) :" << "\033[0m" << std::endl;

	// RPN rpn_copy0(rpn);
	// rpn_copy0.display();
	// std::cout << std::endl;


	// std::cout << "\033[1;34m" << "TEST 3 : RPN & operator=(const RPN & rhs) :" << "\033[0m" << std::endl;

	// RPN rpn_copy1;
	// rpn_copy1 = rpn;
	// rpn_copy1.display();
	// std::cout << std::endl;


    return 0;
}