/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:52:31 by lfabbian          #+#    #+#             */
/*   Updated: 2024/03/25 12:57:12 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>

class PmergeMe
{
	public :

		PmergeMe(int argc, char **argv);				// default constructor
		PmergeMe(PmergeMe const &src);					// copy constructor
		~PmergeMe(void);								// destructor
		PmergeMe &operator=(PmergeMe const &src);		// overloading operator for =

		template <typename T>
		void display(const T& container);

		void mergeInsertSortDeque(std::deque<int>& arr);
		void mergeInsertSortList(std::list<int>& arr);

	private :

		template<typename T>
		void merge(std::list<T>& left, std::list<T>& right, std::list<T>& result);

		template<typename T>
		void mergeInsertionSort(std::list<T>& arr);

		PmergeMe(void);
};

#endif
