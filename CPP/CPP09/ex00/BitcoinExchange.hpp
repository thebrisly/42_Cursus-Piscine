/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:42:49 by lfabbian          #+#    #+#             */
/*   Updated: 2023/10/09 10:19:38 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <fstream>
# include <string>
# include <map>
# include <cstdlib>

class BitcoinExchange {

    public :

        BitcoinExchange(const std::string& filename);
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange &operator=(BitcoinExchange const &src);

    private :

        std::map<std::string, double> _database;

};

#endif