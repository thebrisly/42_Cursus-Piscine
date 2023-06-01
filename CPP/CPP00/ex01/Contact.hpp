/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:26:17 by brisly            #+#    #+#             */
/*   Updated: 2023/06/01 13:36:41 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
//In the .hpp file I always need to declare my classes and the functions' prototype. in the .cpp we write their functions

class Contact {

    // tout ce qui est ici est privé -> je peux les modifier dans des fonctions publiques par exemple mais a definir dans la classe
    private:
        std::string     _firstName;
        std::string     _lastName;
        std::string     _nickname;
        std::string     _secret;
        std::string     _phoneNumber;
        int             _index;

    public:
        Contact();
        ~Contact();

        void savecontact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string secret);
        void showlittle(void) const;
};

#endif