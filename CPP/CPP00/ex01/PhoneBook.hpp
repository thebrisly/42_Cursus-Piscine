/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:25:45 by brisly            #+#    #+#             */
/*   Updated: 2023/06/02 12:10:22 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    private:
        int _size;
        static const int MAX_CONTACTS = 8;
        int _full;

        Contact _contacts[MAX_CONTACTS];
        
    public:
        PhoneBook(int size);
        ~PhoneBook();

        void add_repertory(std::string firstName, std::string lastName, std::string nickname, std::string secret, std::string phoneNumber);
        void show_directory(void) const;
        void show_contact(int index) const;
        int getsize(void);
        void setsize(void);
        int getfull(void);
        void setfull(void);
};

#endif