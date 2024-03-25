/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:52:29 by lfabbian          #+#    #+#             */
/*   Updated: 2024/03/25 10:42:44 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/******************************************/
/* ---- CONSTRUCTORS & DESTRUCTORS ------ */
/******************************************/

PmergeMe::PmergeMe(int argc, char **argv)
{
	std::cout << "\033[90mConstructor for PmergeMe\033[0m" << std::endl;

    std::deque<int> inputDeque;
    std::list<int> inputList;

    srand(time(NULL));
    for (int i = 1; i < argc; ++i)
    {
        int value = atoi(argv[i]);
        if (value <= 0)
        {
            std::cerr << "Error: Only positive integers are allowed." << std::endl;
			exit(1);
        }
        inputDeque.push_back(value);
        inputList.push_back(value);
    }
    std::cout << "Before: ";
    display(inputDeque);

    clock_t start1 = clock();
    mergeInsertSortDeque(inputDeque);
    clock_t end1 = clock();
    double time1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000;

    clock_t start2 = clock();
    mergeInsertSortList(inputList);
    clock_t end2 = clock();
    double time2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000;

    std::cout << "After: ";
    display(inputDeque);
    std::cout << "Time to process a range of " << inputDeque.size() << " elements with std::deque container: " << time1 << " us" << std::endl;
    std::cout << "Time to process a range of " << inputList.size() << " elements with std::list container: " << time2 << " us" << std::endl;
    if (inputDeque == std::deque<int>(inputList.begin(), inputList.end()))
        std::cout << "The sorted sequences are equal." << std::endl;
    else
        std::cout << "The sorted sequences are not equal." << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const &src) {
	(void) src;
	std::cout << "\033[90mCopy constructor for PmergeMe\033[0m" << std::endl;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &src) {
	(void) src;
    std::cout << "\033[90mAssignment operator for PmergeMe\033[0m" << std::endl;
    return *this;
}

PmergeMe::~PmergeMe(void) {
	std::cout << "\033[90mDestructor for PmergeMe\033[0m" << std::endl;
	return ;
}

/******************************************/
/* ------------ TEMPLATE ---------------- */
/******************************************/


template <typename T>
void PmergeMe::display(const T& container)
{
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

/******************************************/
/* ------------ FUNCTIONS --------------- */
/******************************************/

void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr)
{
    std::deque<int>::iterator it1, it2;
    for (it1 = arr.begin() + 1; it1 != arr.end(); ++it1)
    {
        int temp = *it1;
        it2 = it1;
        while (it2 != arr.begin() && *(std::prev(it2)) > temp)
        {
            *it2 = *(std::prev(it2));
            std::advance(it2, -1);
        }
        *it2 = temp;
    }
}

void PmergeMe::mergeInsertSortList(std::list<int>& arr)
{
    std::list<int>::iterator it1, it2;
    for (it1 = ++arr.begin(); it1 != arr.end(); ++it1)
    {
        int temp = *it1;
        it2 = it1;
        while (it2 != arr.begin() && *(std::prev(it2)) > temp)
        {
            *it2 = *(std::prev(it2));
            std::advance(it2, -1);
        }
        *it2 = temp;
    }
}
