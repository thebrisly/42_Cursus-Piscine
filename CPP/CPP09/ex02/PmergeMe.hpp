/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:52:31 by lfabbian          #+#    #+#             */
/*   Updated: 2024/03/25 10:42:49 by lfabbian         ###   ########.fr       */
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

		PmergeMe(int argc, char **argv);
		~PmergeMe(void);
		PmergeMe(PmergeMe const &src);
		PmergeMe	&operator=(PmergeMe const &src);

		template <typename T>
		void display(const T& container);

		void mergeInsertSortDeque(std::deque<int>& arr);
		void mergeInsertSortList(std::list<int>& arr);

	private :

		PmergeMe(void);
};

#endif
