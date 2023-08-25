/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:46:37 by brisly            #+#    #+#             */
/*   Updated: 2023/08/14 13:30:12 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "\033[90mConstructor for Brain called\033[0m" << std::endl;
}

Brain::~Brain() {
    std::cout << "\033[90mDestructor for a Brain called\033[0m" << std::endl;
}

Brain::Brain(const Brain &src) {
    std::cout << "\033[90mCopy constructor Brain called\033[0m" << std::endl;
    int i = 0;

    while (i < 100)
    {
        this->ideas[i] = src.ideas[i];
        i++;
    }
}

Brain &Brain::operator=(const Brain &src) {
    int i = 0;

    while (i < 100)
    {
        this->ideas[i] = src.ideas[i];
        i++;
    }
    return (*this);
}
