/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:42:49 by lfabbian          #+#    #+#             */
/*   Updated: 2023/10/09 16:34:46 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <fstream>
# include <string>
# include <map>
# include <cstdlib>
# include <climits>
# include <algorithm>

class BitcoinExchange {

    public :

        BitcoinExchange(const std::string& filename);
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange &operator=(BitcoinExchange const &src);

        void    display_change(const std::string& filename);
        int     check_values(float value);
        int     check_keys(const std::string& key);

    private :

        std::map<std::string, float> _database;

};

#endif