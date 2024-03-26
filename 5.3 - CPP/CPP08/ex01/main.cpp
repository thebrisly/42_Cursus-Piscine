#include "Span.hpp"

int main()
{
    {
        std::cout << "\033[34m--- Example given in the subject ---\033[0m" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        std::cout << std::endl;
    }   
    std::cout << "----------------------------------" << std::endl;
    {
        std::cout << "\033[34m--- Adding too many numbers ---\033[0m" << std::endl;
        try 
        {
            Span sp = Span(1);
            sp.addNumber(1);
            sp.addNumber(2);
        } 
        catch (std::exception &e) 
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << "----------------------------------" << std::endl;
    {
        std::cout << "\033[34m--- Invalid shortestSpan ---\033[0m" << std::endl;
        try 
        {
            Span sp = Span(1);
            std::cout << sp.shortestSpan() << std::endl;
        } 
        catch (std::exception &e) 
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << "----------------------------------" << std::endl;
    {
        std::cout << "\033[34m--- Invalid longestSpan ---\033[0m" << std::endl;
        try 
        {
            Span sp = Span(1);
            std::cout << sp.longestSpan() << std::endl;
        } 
        catch (std::exception &e) 
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << "----------------------------------" << std::endl;
    {
    	std::cout << "\033[34m--- Try with 11'000 numbers (asked in the subject) ---\033[0m" << std::endl;
        try 
        {
            Span sp = Span(11000);
            for (int i = 0; i < 11000; i++) {
                sp.addNumber(i);
            }
            std::cout << "Shortest span : "<< sp.shortestSpan() << std::endl;
            std::cout << "Longest span : "<< sp.longestSpan() << std::endl;
        } 
        catch (std::exception &e) 
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << "----------------------------------" << std::endl;
    {
        std::cout << "\033[34m--- Using the range function that I created ---\033[0m" << std::endl;
        try
        {
            std::vector<int> vec;
            vec.reserve(5);
            for (int i = 0; i < 5; i++) {
                vec.push_back(i);
            }
            Span sp = Span(5);
		    sp.addRange(vec.begin(), vec.end());
            for (int i = 0; i < 5; i++)
                std::cout << i << std::endl;
            std::cout << "Shortest span : "<< sp.shortestSpan() << std::endl;
            std::cout << "Longest span : "<< sp.longestSpan() << std::endl;
        }
        catch (std::exception &e) 
        {
            std::cout << e.what() << std::endl;
        }
    }

}