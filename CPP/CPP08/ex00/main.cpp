#include "easyfind.hpp"
#include <list>
#include <deque>

int main()
{
    std::cout << "\033[34m--- Creating a container of integers ---\033[0m" << std::endl;
    //std::vector<int> cont = {1, 2, 3, 4, 5, 43}; //this command would be good but it's c++ 11 - too bad. I need to do all this shit instead :

    // TRYING WITH DIFFERENT TYPES OF VECTORS : (just decomment the line that you wanna test)

    std::vector<int> cont;
    //std::list<int> cont;
    //std::deque<int> cont;

    cont.push_back(1);
    cont.push_back(2);
    cont.push_back(3);
    cont.push_back(4);
    cont.push_back(5);
    cont.push_back(43);

    int correct_to_find = 3;
    int wrong_to_find = 42;

    std::cout << "Calling the easyfind() function once to search " << correct_to_find << " (possible) and another time to find " << wrong_to_find << " (not possible)\n" << std::endl;
    try 
    {
        std::cout << "\033[32m~ Correct search : result\033[0m" << std::endl;
        easyfind(cont, correct_to_find);

        std::cout << "\n";

        std::cout << "\033[31m~ Wrong search : result\033[0m" << std::endl;
        easyfind(cont, wrong_to_find);
    }
    catch (std::exception &e) 
    {
		std::cout << e.what() << std::endl;
    }
}