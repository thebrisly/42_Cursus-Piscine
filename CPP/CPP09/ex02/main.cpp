#include "PmergeMe.hpp"
#include <sstream>

int main(int argc, char* argv[])
{

	if (argc <= 2)
	{
		std::cerr << "Error" <<std::endl;
		return 0;
	}

	std::deque<unsigned int> deq_to_sort;
	std::list<unsigned int> list_to_sort;

	argv++;
	while (argc > 1)
	{
		std::string str(*argv);

		std::istringstream myStreamUI(str);
		std::istringstream myStreamLI(str);

		unsigned int numberUI;
		long int numberLI;

		myStreamUI >> numberUI;
		myStreamLI >> numberLI;

		if (myStreamUI.fail() || numberLI < 0)
		{
			std::cout << "Error" << std::endl;
			return 0;
		}
		else
		{
			list_to_sort.push_back(numberUI);
			deq_to_sort.push_back(numberUI);
		}

		argc--;
		argv++;
	}

	PmergeMe pmm = PmergeMe(list_to_sort, deq_to_sort);

	pmm.sort_all();


	return 0;
}