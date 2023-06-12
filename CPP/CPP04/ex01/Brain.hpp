/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:43:42 by brisly            #+#    #+#             */
/*   Updated: 2023/06/12 12:30:48 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>
# include <iostream>

class Brain {
    public:
        Brain();
        Brain(Brain const &src);
        Brain& operator=(Brain const &src);
        ~Brain();

    protected:
        std::string ideas[100];
};

#endif