/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:52:29 by lfabbian          #+#    #+#             */
/*   Updated: 2024/03/25 12:57:11 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/******************************************/
/* ---- CONSTRUCTORS & DESTRUCTORS ------ */
/******************************************/

PmergeMe::PmergeMe(void) {
	std::cout << "\033[90mConstructor for PmergeMe\033[0m" << std::endl;
}

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
            std::cerr << "\033[1;31mError: Only positive integers are allowed.\033[0m" << std::endl;
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

template<typename T>
void PmergeMe::merge(std::list<T>& left, std::list<T>& right, std::list<T>& result) {
    typename std::list<T>::iterator left_it = left.begin();
    typename std::list<T>::iterator right_it = right.begin();

    while (left_it != left.end() && right_it != right.end()) {
        if (*left_it < *right_it) {
            result.push_back(*left_it);
            ++left_it;
        } else {
            result.push_back(*right_it);
            ++right_it;
        }
    }

    result.insert(result.end(), left_it, left.end());
    result.insert(result.end(), right_it, right.end());
}

template<typename T>
void PmergeMe::mergeInsertionSort(std::list<T>& arr) {
    std::list<std::list<T> > lists;
    typename std::list<T>::iterator it;

    for (it = arr.begin(); it != arr.end(); ++it) {
        std::list<T> singleton;
        singleton.push_back(*it);
        lists.push_back(singleton);

        while (lists.size() >= 2) {
            std::list<T> first = lists.front();
            lists.pop_front();
            std::list<T> second = lists.front();
            lists.pop_front();

            std::list<T> merged;
            merge(first, second, merged);
            lists.push_back(merged);
        }
    }

    if (!lists.empty())
        arr = lists.front();
}

/******************************************/
/* ------------ FUNCTIONS --------------- */
/******************************************/

void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr) {
    std::list<int> tempList(arr.begin(), arr.end());
    mergeInsertionSort(tempList);
    arr.assign(tempList.begin(), tempList.end());
}

void PmergeMe::mergeInsertSortList(std::list<int>& arr) {
    mergeInsertionSort(arr);
}
