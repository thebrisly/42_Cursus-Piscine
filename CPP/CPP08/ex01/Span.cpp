#include "Span.hpp"

Span::Span(unsigned int N) : _size(N)
{
    std::cout << "\033[90mConstructor for Span called\033[0m" << std::endl;
    this->_container.reserve(this->_size);
}

Span::~Span()
{
    std::cout << "\033[90mDestructor for Span called\033[0m" << std::endl;
}

Span::Span(const Span &src)
{
    std::cout << "\033[90mCopy constructor for Span called\033[0m" << std::endl;
    *this = src;
}

Span &Span::operator=(const Span &src) 
{
    std::cout << "\033[90mAssignement operator for Span called\033[0m" << std::endl;
	this->_container.reserve(this->_size);
	this->_container = src._container;
	return *this;
}

// -------------- METHODS -------------

void Span::addNumber(int number)
{
    if (this->_container.size() == this->_size)
        throw TooManyNumbersException();
    this->_container.push_back(number);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (static_cast<unsigned int>(std::distance(begin, end)) > (this->_size - this->_container.size()))

        throw TooFewNumbersException();
    this->_container.insert(_container.end(), begin, end);
    
}

int Span::shortestSpan()
{
    if (this->_container.size() <= 1)
        throw TooFewNumbersException();

    std::sort(this->_container.begin(), this->_container.end());
    
    int smallest = this->_container[1] - this->_container[0];
    for (unsigned int i = 2; i < this->_size; i++) 
    {
        int current = this->_container[i] - this->_container[i - 1];
        if (current < smallest)
            smallest = current;
    }
    return (smallest);
}

int Span::longestSpan()
{
    if (this->_container.size() <= 1)
        throw TooFewNumbersException();
    int max, min;
    max = *max_element(this->_container.begin(), this->_container.end());
    min = *min_element(this->_container.begin(), this->_container.end());
    return (max - min);
}

