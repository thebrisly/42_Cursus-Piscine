/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 08:06:39 by brisly            #+#    #+#             */
/*   Updated: 2023/06/12 08:30:50 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << "\033[90mConstructor for a WrongCat called\033[0m" << std::endl;
    this->type = "Cat Impostor";
}

WrongCat::~WrongCat() {
    std::cout << "\033[90mDestructor for a WrongCat called\033[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src) {
    std::cout << "\033[90mCopy constructor WrongCat called\033[0m" << std::endl;
    *this = src;
}

WrongCat &WrongCat::operator=(const WrongCat &src) {
    this->type = src.type;
    return (*this);
}

void WrongCat::makeSound() const {
    std::cout << "WRONG MIAOUUUUUUU" << std::endl;
}
