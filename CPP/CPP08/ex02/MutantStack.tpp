#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP
# include "MutantStack.hpp"

MutantStack::MutantStack()
{
    std::cout << "\033[90mConstructor for MutantStack called\033[0m" << std::endl;
}

MutantStack::~MutantStack()
{
    std::cout << "\033[90mDestructor for MutantStack called\033[0m" << std::endl;
}

MutantStack::MutantStack(const MutantStack &src)
{
    std::cout << "\033[90mCopy constructor for MutantStack called\033[0m" << std::endl;
    *this = src;
}

MutantStack	&MutantStack::operator=(MutantStack const &src)
{
    std::cout << "\033[90mAssignment operator for MuntantStack called\033[0m" << std::endl;
	return *this;
}

//Dans la classe MutantStack que vous avez fournie, c est en fait un membre hérité de la classe std::stack<T>. 
//La classe std::stack est basée sur un conteneur sous-jacent (par défaut, std::deque) qui stocke les éléments de la pile. 
//La variable c dans std::stack représente ce conteneur sous-jacent.

iterator begin()
{
    return (this->c.begin());
}

iterator end()
{
    return (this->c.end());
}

#endif