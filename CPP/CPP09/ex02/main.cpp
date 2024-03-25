/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:52:26 by lfabbian          #+#    #+#             */
/*   Updated: 2024/03/25 10:11:07 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc <= 1)
    {
        std::cerr << "Warning ! You need to give me a sequence of positive integers." << std::endl;
        return 1;
    }
	PmergeMe pmergeMe(argc, argv);
	(void)pmergeMe;
}
