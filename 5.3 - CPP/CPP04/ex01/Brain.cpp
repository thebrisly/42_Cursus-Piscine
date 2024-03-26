/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:46:37 by brisly            #+#    #+#             */
/*   Updated: 2023/08/14 13:23:27 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default Brain constructor called." <<std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called." << std::endl;
}

Brain& Brain::operator=(Brain const &src)
{
	for (int i = 0; i < 100; ++i)
	{
		(this->_ideas)[i] = src.getIdea(i);
	}
	return *this;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index <= 100)
	{
		return (this->_ideas)[index];
	}
	return 0;
}

void Brain::setIdea(int index, std::string const &idea)
{
	if (index >= 0 && index <= 100)
	{
		this->_ideas[index] = idea;
	}
}

Brain::Brain(Brain const &src)
{
	*this = src;
}
