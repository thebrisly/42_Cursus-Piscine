#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP
# include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
{
    std::cout << "\033[90mConstructor for MutantStack called\033[0m" << std::endl;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
    std::cout << "\033[90mDestructor for MutantStack called\033[0m" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &src)
{
    std::cout << "\033[90mCopy constructor for MutantStack called\033[0m" << std::endl;
    *this = src;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &src)
{
    std::cout << "\033[90mAssignment operator for MutantStack called\033[0m" << std::endl;
    // Implémentez la logique de l'opérateur d'assignation ici
    return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return (this->c.end());
}

#endif
