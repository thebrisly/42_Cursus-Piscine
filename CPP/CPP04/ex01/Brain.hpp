/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:43:42 by brisly            #+#    #+#             */
/*   Updated: 2023/08/14 13:23:40 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>
# include <iostream>

class Brain
{
	private:
		std::string _ideas[100];

	public:
		Brain();
		Brain& operator=(Brain const &src);
		Brain(Brain const &rhs);
		~Brain();

		std::string	getIdea(int index) const;
		void		setIdea(int index, std::string const &idea);
};

#endif
