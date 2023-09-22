#ifndef SPAN_HPP
# define SPAN_HPP
# include <algorithm>
# include <iostream>
# include <vector>

class Span
{
    public :

        Span(unsigned int N);
        Span(const Span &src);
        ~Span();
        Span &operator=(const Span &src);

        void addNumber(int number);
        void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        void addRange();
        int shortestSpan();
        int longestSpan();

    private :

        unsigned int        _size;
        std::vector<int>    _container;

    class TooManyNumbersException : public std::exception
    {
        public :

            virtual const char *what() const throw()
            {
                return ("\033[31mThe capacity of this container is full sorry - TRY AGAIN\033[0m");
            }
    };

    class TooFewNumbersException : public std::exception
    {
        public :

            virtual const char *what() const throw()
            {
                return ("\033[31m There's not enough numbers to find a span \033[0m");
            }
    };

};

#endif