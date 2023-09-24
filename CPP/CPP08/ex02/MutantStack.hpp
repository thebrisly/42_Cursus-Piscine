#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP // # pragma once is the same thing as the two first lines here above
# include <iostream>
# include <algorithm>
# include <vector>
# include <stack>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
    public :

        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack &src);
        MutantStack &operator=(MutantStack const &src);

        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin();
        iterator end();
};

#endif